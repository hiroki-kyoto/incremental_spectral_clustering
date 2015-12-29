import os
import Image

prefix = 'pics/';
im_names = os.listdir(prefix);
im = Image.open(prefix + im_names[0]);
im.show();
