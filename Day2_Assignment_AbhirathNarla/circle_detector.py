import cv2
import numpy as np
import matplotlib.pyplot as plt
def preprocess_image (image_path):
    image = cv2.imread(image_path)
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    grayblur = cv2.medianBlur(gray, 5)
    graycontrast = np.clip(grayblur.astype(np.float32)*1.5, 0, 255).astype(np.uint8)
    return image, graycontrast

def detectcircles (graycontrast, dp=1, minDist = 20, param1=40, param2 = 30, minRadius = 5, maxRadius = 100):
    circles = cv2.HoughCircles(graycontrast, cv2.HOUGH_GRADIENT, dp=dp, minDist=minDist, param1=param1, param2=param2, minRadius=minRadius, maxRadius=maxRadius)
    return circles

def visualisecircles (image, circles, savepath = None):
    if circles is not None:
        circles = np.around(circles).astype(np.uint16)
        for circle in circles[0,:]:
            x, y, r = circle
            cv2.circle(image, (x,y), r, (0,255,0), 2)
            cv2.circle(image, (x,y), 2, (0,0,255), 2)
    pass

def calculatestatistics (circles):
    radius = 0
    num =0
    if circles is not None:
        circles = np.around(circles).astype(np.uint16)
        radcirc = circles[0,:,2]
        rmin = np.min(radcirc)
        rmax = np.max(radcirc)
        range = rmax - rmin
        lower = rmin + range/3
        upper = rmin + 2*range/3
        for circle in circles[0,:]:
            x, y, r = circle
            radius += r
            num += 1
            if r>upper:
                size = "(Large)"
            elif r<lower:
                size = "(Small)"
            else:
                size = "(Medium)"
            print("Circle ", num, ": Centre and Radius: (", x,",", y, ")"," & ", r, size)
    
    print("Average Radius = ", np.mean(radcirc))
    print("Number of circles: ", num)
    print("Min and Max radius: ", rmin, ", ", rmax)
    pass

def main():
    image_path = input("Please enter the image path without '': ")
    ##savepath = input("Please enter save path: ")
    if cv2.imread(image_path) is None:
        print("Error: Image not found")
    else: 
        image , grayblur =preprocess_image(image_path)
        circles = detectcircles(grayblur)
        result = image.copy()
        visualisecircles(result, circles, None)
        calculatestatistics(circles)
        fig, axes = plt.subplots(1,2, figsize = (15,10))
        axes = axes.ravel()
        axes[0].imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
        axes[0].set_title('Original')
        axes[1].imshow(cv2.cvtColor(result, cv2.COLOR_BGR2RGB))
        axes[1].set_title('Circle Detection')
        plt.show()
    pass

main()






            
