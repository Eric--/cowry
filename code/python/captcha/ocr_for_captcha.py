#encoding=utf-8
import Image,ImageEnhance,ImageFilter
import sys

image_name = "./22.jpeg"

#ȥ�� ���ŵ�
im = Image.open(image_name)
im = im.filter(ImageFilter.MedianFilter())
enhancer = ImageEnhance.Contrast(im)
im = enhancer.enhance(2)
im = im.convert('1')

#im.show() #���Բ鿴

s = 12      #��ʼ �и�� x
t = 2       #��ʼ �и�� y

w = 10      #�и� �� +y
h = 15      #�и� �� +x

im_new = []
for i in range(4): #��֤���и�
    im1 = im.crop((s+w*i+i*2,t,s+w*(i+1)+i*2,h))
    im_new.append(im1)

#im_new[0].show()#���Բ鿴

xsize, ysize = im_new[0].size
gd = []
for i in range(ysize):
    tmp=[]
    for j in range(xsize):
        if( im_new[0].getpixel((j,i)) == 255 ):
            tmp.append(1)
        else:
            tmp.append(0)
    gd.append(tmp)

#��Ч��
for i in range(ysize):
    print gd[i]
