#-*- coding:utf-8 -*-
import numpy as np
import cv2 as cv
import dlib
from scipy.spatial import distance
import datetime
import threading
from queue import Queue

# 调用人脸检测器
detector = dlib.get_frontal_face_detector()
predictor = dlib.shape_predictor("C:/Users/Administrator/Desktop/5.8/debug/shape_predictor_68_face_landmarks.dat")
now_time = datetime.datetime.now()

class Face:
    def __init__(self):
        self.LeftEye_Start = 36
        # 设定人眼标定点
        self.LeftEye_End = 41
        self.RightEye_Start = 42
        self.RightEye_End = 47
        # 设定嘴巴标定点
        self.OutMouth_Start = 48
        self.OutMouth_Mid= 51
        self.OutMouth_End = 59
        self.InMouth_Start = 60
        self.InMouth_End = 67
        # 横纵比阈值
        self.Closed_Radio = 0.25
        # 意味着连续多少帧横纵比小于Closed_Radio小于阈值时，判断疲劳
        self.Closed_Radio_constant_high = 30
        self.Closed_Radio_constant_low = 15
        # 横纵比阈值
        self.Blink_Radio = 0.2
        # 当Radio小于阈值时，接连多少帧会发生眨眼动作
        self.Blink_Radio_constant = 2
        # 张口度阈值
        self.Yawn_Radio = 0.65
        # 意味着连续多少帧横纵比小于Radio小于阈值时，判断疲劳
        self.Low_radio_constant2 = 15
        self.LeftEye_Start = 36
        self.LeftEye_End = 41
        self.RightEye_Start = 42
        self.RightEye_End = 47
        # 眼部状态数据
        self.eye_status = 'Awaking'
        self.eye_level = 'green'

    def calculate_Ratio(self,eye):
        """
        计算眼睛横纵比
        """
        d1 = distance.euclidean(eye[1], eye[5])
        d2 = distance.euclidean(eye[2], eye[4])
        d3 = distance.euclidean(eye[0], eye[3])
        ratio = (d1 + d2) / (2 * d3)
        return ratio

    def calculate_Distance(self,eye):
        """
        计算眼睛上下距离
        """
        d1 = distance.euclidean(eye[1], eye[5])
        d2 = distance.euclidean(eye[2], eye[4])
        d3 = distance.euclidean(eye[0], eye[3])
        d4 = (d1 + d2)/2
        dis = d4
        return dis

    def calculate_mouthRatio(self,mouth):
        """
        计算张口度
        """
        d1 = distance.euclidean(mouth[1], mouth[7])
        d2 = distance.euclidean(mouth[2], mouth[6])
        d3 = distance.euclidean(mouth[3], mouth[5])
        d4 = distance.euclidean(mouth[0], mouth[4])
        d5 = max(d1, d2, d3)
        ratio = d5 / d4
        return ratio

    def characteristic_points(self, gray, rect):
        shape = predictor(gray, rect)
        points = np.zeros((68, 2), dtype=int)
        for i in range(68):
            points[i] = (shape.part(i).x, shape.part(i).y)
        return points

def yawn_detection(face, points, frame,starttime):

    global yawn_60s
    global yawn_10s
    global yawn_list
    global frame_counter2   # 连续帧计数
    global yawn_status
    global is_print2

    # 获取嘴巴特征点
    OutMouth = points[face.OutMouth_Start: face.OutMouth_End + 1]
    # MidMouth = points[OutMouth_Mid: OutMouth_End + 1]
    InMouth = points[face.InMouth_Start: face.InMouth_End + 1]
    ratio = face.calculate_mouthRatio(InMouth)

    # 凸包检测
    left_mouth_hull = cv.convexHull(OutMouth)
    # mid_Mouth_hull=cv.convexHull(OutMouth_Mid)
    right_mouth_hull = cv.convexHull(InMouth)

    # 绘制轮廓
    cv.drawContours(frame, [left_mouth_hull], -1, [255, 0, 0], 1)
    # cv.drawContours(frame, [mid_Mouth_hull], -1, [0, 255, 0], 1)
    cv.drawContours(frame, [right_mouth_hull], -1, [255, 0, 0], 1)

    # 哈欠判断
    endtime = datetime.datetime.now()

    time = (endtime - starttime).seconds

    cv.putText(frame, "time: {} s".format(time), (500, 60), cv.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
    # cv.putText(frame, str(ratio), (500, 150), cv.FONT_HERSHEY_SIMPLEX, 0.7, [0, 0, 255], 2)
    if ratio >= face.Yawn_Radio:
        frame_counter2 += 1
        # cv.putText(frame, str(frame_counter2), (500, 120), cv.FONT_HERSHEY_SIMPLEX, 0.7, [0, 0, 255], 2)
        if frame_counter2 >= face.Low_radio_constant2:
            cv.putText(frame, "yawn warning!", (50, 60), cv.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
            if yawn_status == False:

                yawn_10s += 1
                yawn_status = True
    else:
        frame_counter2 = 0
        yawn_status = False
    yawn_60s += yawn_10s
    if yawn_60s < 1:
        level = 'green'
    if 1 <= yawn_60s < 3:
        level = 'yellow'
    if yawn_60s >= 3:
        level = 'red'

    # 10秒记录一次哈欠数
    if time % 10 == 0:
        if (len(yawn_list) > 0):
            if yawn_list[len(yawn_list)-1][2] != time:
                print((yawn_10s, level, time))
                yawn_list.append((yawn_10s, level, time))
                with open('C:/Users/Administrator/Desktop/5.8/debug/biyanhaqianshuju.txt', 'a') as f:
                    f.write('{},{},;\n'.format(yawn_10s, level))
                yawn_10s = 0
        else:
            yawn_list.append((yawn_10s, level, time))
    if time % 60 == 0 and is_print2 == False:
        print(yawn_list)
        yawn_60s = 0
        is_print2 = True
    if time % 60 != 0:
        is_print2 = False

def sleepy_detection(face, points, frame, starttime):

    global alarm   # 初始化警报
    global frame_counter  # 连续帧计数

    global blink_counter  # 眨眼计数
    global frame_counter1  # 连续帧计数
    global eye_captimes
    global is_print1
    # 获取眼睛特征点
    Lefteye = points[face.LeftEye_Start: face.LeftEye_End + 1]
    Righteye = points[face.RightEye_Start: face.RightEye_End + 1]

    # 计算眼睛横纵比
    Lefteye_Ratio = face.calculate_Ratio(Lefteye)
    Righteye_Ratio = face.calculate_Ratio(Righteye)
    mean_Ratio = (Lefteye_Ratio + Righteye_Ratio) / 2  # 计算两眼平均比例
    dis1 = face.calculate_Distance(Lefteye)
    dis2 = face.calculate_Distance(Righteye)
    dis3 = (dis1 + dis2) / 2
    # 计算凸包
    left_eye_hull = cv.convexHull(Lefteye)
    right_eye_hull = cv.convexHull(Righteye)

    # 绘制轮廓
    cv.drawContours(frame, [left_eye_hull], -1, [255, 0, 0], 1)
    cv.drawContours(frame, [right_eye_hull], -1, [255, 0, 0], 1)

    # 闭眼判断
    if mean_Ratio < face.Closed_Radio:
        frame_counter += 1
        if frame_counter < face.Closed_Radio_constant_low:
            face.eye_level = 'green'
            face.eye_status = 'Awaking'
        if face.Closed_Radio_constant_low <= frame_counter < face.Closed_Radio_constant_high:
            face.eye_level = 'yellow'
            face.eye_status = 'lightly fatigue'
        if frame_counter >= face.Closed_Radio_constant_high:
            face.eye_level = 'red'
            face.eye_status = 'Deeply fatigue!'
            # 发出警报
            if not alarm:
                alarm = True
    else:
        alarm = False
    cv.putText(frame, face.eye_status, (50, 30), cv.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)




    cv.putText(frame, "Ratio{:.2f}".format(mean_Ratio), (300, 30), cv.FONT_HERSHEY_SIMPLEX, 0.7, [0, 0, 255], 2)
    cv.putText(frame, "dis{:.2f}".format(dis3), (300, 60), cv.FONT_HERSHEY_SIMPLEX, 0.7, [0, 0, 255], 2)

    # 眨眼判断
    if mean_Ratio < face.Blink_Radio:
        frame_counter1 += 1
    else:
        if frame_counter1 >= face.Blink_Radio_constant:
            blink_counter += 1
            frame_counter1 = 0

    cv.putText(frame, "Blingks{}".format(blink_counter), (500, 30), cv.FONT_HERSHEY_SIMPLEX, 0.7, [0, 0, 255], 2)

    # return frame_counter, level
    endtime = datetime.datetime.now()
    time = (endtime - starttime).seconds
    if time > 1:
        if time % 10 == 0 and is_print1 == False:
            is_print1 = True
            print(frame_counter, '\t', eye_captimes)
            perclos = float(frame_counter) / eye_captimes
            print('perclos为{}，疲劳等级为{}'.format(perclos, face.eye_level))
            with open('C:/Users/Administrator/Desktop/5.8/debug/biyanhaqianshuju.txt', 'a') as f:
                f.write('*{},{},'.format(perclos, face.eye_level))
            frame_counter = 0
            eye_captimes = 0
            face.eye_status = 'Awaking'
        if time % 10 != 0:
            is_print1 = False

def hough(face, points, frame):

    biyan = 0

    # 获取眼睛特征点
    Lefteye = points[face.LeftEye_Start: face.LeftEye_End + 1]
    Righteye = points[face.RightEye_Start: face.RightEye_End + 1]

    # 计算眼睛横纵比
    Lefteye_Ratio = face.calculate_Ratio(Lefteye)
    Righteye_Ratio = face.calculate_Ratio(Righteye)
    mean_Ratio = (Lefteye_Ratio + Righteye_Ratio) / 2  # 计算两眼平均比例
    dis1 = face.calculate_Distance(Lefteye)
    dis2 = face.calculate_Distance(Righteye)
    dis3 = (dis1 + dis2) / 2
    # 计算凸包
    left_eye_hull = cv.convexHull(Lefteye)
    right_eye_hull = cv.convexHull(Righteye)

    # 眼部疲劳检测

    # mask
    ROI = np.zeros(frame.shape, np.uint8) * 255
    cv.drawContours(ROI, [left_eye_hull], -1, [255, 255, 255], -1)
    imgroi = cv.bitwise_and(frame, ROI)
    x, y, w, h = cv.boundingRect(left_eye_hull)
    gray = cv.cvtColor(imgroi, cv.COLOR_BGR2GRAY)
    # ret, binary = cv.threshold(gray, 0, 255, cv.THRESH_BINARY)

    ret, binary2 = cv.threshold(gray, 35, 255, cv.THRESH_BINARY)
    eye_img = binary2[y:y + h, x:x + w]
    circles = cv.HoughCircles(binary2[y:y + h, x:x + w],  # 输入图像
                              cv.HOUGH_GRADIENT,  # 检测方法
                              1,  # 图像分辨率和累加器比值
                              50,  # 圆中心最小距离
                              param1=100,  # 霍夫梯度法传递给canny边缘检测算子的高阈值，默认100
                              param2=6,  # 霍夫梯度法它表示在检测阶段圆心的累加器阈值，越小就越可以检测到更多根本不存在的圆，越大，能通过检测的圆就更加接近完美圆
                              minRadius=2,  # 最小圆半径，默认值0
                              maxRadius=300  # 最大圆半径，默认值0
    )
    try:
        if (len(circles[0]) > 0):
            num_cir = len(circles[0])
            # 输出检测到圆的个数
            print("检测到{}个圆".format(num_cir))
            cv.putText(frame, "open", (500, 60), cv.FONT_HERSHEY_SIMPLEX, 0.7, [0, 0, 255], 2)
            print('-------------我是条分割线-----------------')
            # 根据检测到圆的信息，画出每一个圆
            for circle in circles[0]:
                # 圆的基本信息
                # print(circle[2])
                # 坐标行列
                circlex = int(circle[0])
                circley = int(circle[1])
                # 半径
                circler = int(circle[2])
                # 在原图用指定颜色标记出圆的位置
                cv.circle(frame, (x + circlex, y + circley), circler, (0, 255, 255), -1)
                # 显示新图像

                # else:
                #     cv.putText(frame, "闭眼", (500, 60), cv.FONT_HERSHEY_SIMPLEX, 0.7, [0, 0, 255], 2)
    except TypeError:
        print("出错,未检测到瞳孔")
        biyan += 1
        cv.putText(frame, "close", (500, 60), cv.FONT_HERSHEY_SIMPLEX, 0.7, [0, 0, 255], 2)

    if biyan < 4:
        cv.putText(frame, "green", (500, 90), cv.FONT_HERSHEY_SIMPLEX, 0.7, [0, 0, 255], 2)
    elif 4 <= biyan < 6:
        cv.putText(frame, "yellow", (500, 90), cv.FONT_HERSHEY_SIMPLEX, 0.7, [0, 0, 255], 2)
    else:
        cv.putText(frame, "red", (500, 90), cv.FONT_HERSHEY_SIMPLEX, 0.7, [0, 0, 255], 2)

def shutdown():
    global shutdownflag
    shutdownflag = True
    pass

# 全局变量
alarm = False       # 初始化警报
frame_counter = 0   # 闭眼帧计数
blink_counter = 0   # 眨眼计数
frame_counter1 = 0  # 连续帧计数
yawn_60s = 0        # 一分钟哈欠次数
yawn_10s = 0        # 10秒哈欠数
eye_captimes = 0    # 拍摄帧数

frame_counter2 = 0
yawn_status = False
yawn_list = []
is_print1 = False
is_print2 = False
shutdownflag = False
def main():
    """
    主函数
    """
    global shutdownflag

    cap = cv.VideoCapture(0)  # 0摄像头摄像
    if shutdownflag == False:
        starttime = datetime.datetime.now()
        # 实例化face对象
        face = Face()
        while cap.isOpened():
            # 帧数计数器
            global eye_captimes
            eye_captimes += 1
            ret, frame = cap.read()  # 读取每一帧
            frame = cv.flip(frame, 1)
            if ret:
                gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
                rects = detector(gray, 0)  # 人脸检测
                for rect in rects:
                    points = face.characteristic_points(gray, rect)
                    sleepy_detection(face, points, frame, starttime)
                    yawn_detection(face, points, frame, starttime)
                cv.imshow("fatigue_detection", frame)
                if cv.waitKey(100) & 0xFF == ord('q'):
                    break
        # print(yawn_list)
        cap.release()
        cv.destroyAllWindows()
    else:
        cap.release()
        cv.destroyAllWindows()

if __name__ == '__main__':
    main()