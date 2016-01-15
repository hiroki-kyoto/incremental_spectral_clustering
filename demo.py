import os
import commands as cmd
import Image as im
import numpy as np

# settings
prefix = 'pics/'
outim = 'out.jpg'
r = 3

# test data
files = os.listdir(prefix)
demo = im.open(prefix + files[0])
#demo.show()

# matrix data of pixels
w,h = demo.size
data = np.array(demo)

def sim(p1, p2) :
    s = np.sum((p1[0]-p2[0])*(p1[0]-p2[0]))
    if s==0 :
        return 1.0
    c = np.sum((p1[1]-p2[1])*(p1[1]-p2[1]))
    return 1.0/(s*(1.0+c))

# filter application on image data
tick = h*w-1

while tick>=0 :
    #print tick
    x1 = tick/w
    y1 = tick%w
    
    tick -= 1
    
    s1 = np.array([x1,y1])
    c1 = np.array(data[x1][y1])
    
    minx = max(0, x1 - r)
    maxx = min(h-1, x1 + r)
    miny = max(0, y1 - r)
    maxy = min(w-1, y1 + r)
    s2 = np.array([minx,miny])
    c2 = np.array(data[maxx][maxy])
    sim([s1,c1], [s2,c2])
    
    #for x2 in xrange(minx, maxx+1) :
    #    for y2 in xrange(miny, maxy+1) :
    #        a=data[x2][y2]*2.0
    #        s2 = np.array([x2,y2])
    #        c2 = np.array(data[x2][y2])
    #        sim([s1,c1],[s2,c2])

# save data as image and show
#bim = im.fromarray(data.astype('uint8'), mode='RGB')
#bim.save(outim)
#bim.show()

#just for png support
#[status, output] = cmd.getstatusoutput('shotwell '+ outim)

