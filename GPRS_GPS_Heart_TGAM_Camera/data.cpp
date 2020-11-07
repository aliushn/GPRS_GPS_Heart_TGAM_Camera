#include "mywidget.h"

extern Drive_INFO Drive;
/*------------------GPS数据整合---------------------*/
QString MyWidget::GPSDataIn(GPS_INFO *GPS){
    qint64 tim = QDateTime::currentDateTime().toMSecsSinceEpoch(); //毫秒级，获取时间戳
    GPS->Position="position";
    GPS->Tim=tim;
    return QString("%1,%2,%3,%4,%5,%6").arg(GPS->Position)
            .arg(Drive.Vid,0,10).arg(GPS->Tim).arg(GPS->latitude,0,'r',4)
            .arg(GPS->longitude,0,'r',4).arg(GPS->speed,0,'r',2);
}


/*------------------上下车数据整合---------------------*/
QString MyWidget::logDataIn(QString State1){
    qint64 tim = QDateTime::currentDateTime().toMSecsSinceEpoch(); //毫秒级，获取时间戳
    Drive_INFO Drive1;
    Drive1.Drive="drive";
    Drive1.Tim=tim;
    Drive1.Action=1;//下车
    Drive1.State=State1;//疲劳状态
    return QString("%1,%2,%3,%4,%5,%6").arg(Drive1.Drive)
            .arg(Drive.Did,0,10).arg(Drive.Vid,0,10).arg(Drive1.Tim)
            .arg(Drive1.Action,0,10).arg(Drive1.State);
}

/*------------------生理特征数据整合---------------------*/
QString MyWidget::PhysicalDataIn(){
    qint64 tim = QDateTime::currentDateTime().toMSecsSinceEpoch(); //毫秒级，获取时间戳
    physicalData.Physical="physical";
    if(timeheart!=0){
        physicalData.HeartCurrent=int(sumheart/timeheart);
    }
    else{
        physicalData.HeartCurrent=0;
    }
    if(timemenditain!=0){
    physicalData.Attention=int(summenditain/timemenditain);
    }
    else{
    physicalData.Attention=0;
    }
    sumheart=0;summenditain=0;timeheart=0;timemenditain=0;
    physicalData.Tim=tim;
    return QString("%1,%2,%3,%4,%5,%6,%7").arg(physicalData.Physical)
            .arg(Drive.Did,0,10).arg(physicalData.HeartCurrent).arg(physicalData.Attention)
            .arg(physicalData.Eye).arg(physicalData.Yawn).arg(physicalData.Tim);
}
