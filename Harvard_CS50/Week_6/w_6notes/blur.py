#illustrates how to blur an image using python

#imports from the PIL library image and image filter
from PIL import Image, ImageFilter

#save an image named before as bmp file bridge
before = Image.open("bridge.bmp")

#save an image named after to be the equivalent of the before image filtered with the blur image filter
after = before.filter(ImageFilter.BLUR)

#save the after file as an bmp image named out
after.save("out.bmp")
