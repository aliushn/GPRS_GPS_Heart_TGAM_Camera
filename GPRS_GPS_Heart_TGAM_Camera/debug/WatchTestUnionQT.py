import numpy as np
import matplotlib.pyplot as plt
from scipy import integrate

MAXNUM = 32         # data size
FFTpoint = 1024     # fft point
ratio = 1           # resize ratio
input_filename = 'C:/Users/Administrator/Desktop/5.8/debug/Heart.txt'
output_filename = 'C:/Users/Administrator/Desktop/5.8/debug/HRV.txt'

if __name__ == '__main__':
    with open(input_filename, 'r') as f:
        b = np.zeros(MAXNUM)
        for i in range(MAXNUM):
            fstr = f.readline()
            b[i] = int(fstr.strip())

        b_single = b
        for i in range(ratio - 1):
            b = np.append(b, b_single)
        #print(b)

        seriesFFT = np.abs(np.fft.fft(b, FFTpoint))
        p = (seriesFFT ** 2) / FFTpoint

        xFFT = np.linspace(0, 6.9, int(FFTpoint / 2), endpoint=False)

        p = p[range(int(FFTpoint / 2))]

        for i in range(int(FFTpoint / 2)):
            if (xFFT[i] >= 0.04 and xFFT[i - 1] <= 0.04):
                aa = i
            if (xFFT[i] >= 0.15 and xFFT[i - 1] <= 0.15):
                bb = i
            if (xFFT[i] >= 0.4 and xFFT[i - 1] <= 0.4):
                cc = i
        #print(aa,bb,cc)

        res1 = integrate.simps(p[aa - 1:bb], xFFT[aa - 1:bb])
        res2 = integrate.simps(p[bb - 1:cc], xFFT[bb - 1:cc])
        HRV = res1/res2
        print("{:.3f}".format(HRV))

        # plt.plot(xFFT, p)
        # plt.xlabel('f/Hz')
        # plt.ylabel('PSD/(ms*ms/Hz)')
        # plt.show()
        f.close()

    with open(output_filename, 'a') as f:
        f.write("{:.3f}".format(HRV)+'\r\n')
        f.close()

