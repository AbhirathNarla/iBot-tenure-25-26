import cv2
import matplotlib.pyplot as plt
import numpy as np
import os

def display(original, sketch, output_path = None):
    fig, axes = plt.subplots(1, 2, figsize=(14, 7))

    axes[0].imshow(cv2.cvtColor(original,cv2.COLOR_BGR2RGB))
    axes[0].set_title("Original")
    axes[0].axis('off')

    axes[1].imshow(sketch, cmap='gray')  
    axes[1].set_title("Sketch")
    axes[1].axis('off')
    plt.show()
    # Save edge image if output folder specified
    if output_path!= '':
        output_name = f'sketch.png'
        output_path = os.path.join(output_path, output_name)
        cv2.imwrite(output_path, sketch)
        print(f' Saved: {output_path}')
    pass

def main():
    filepath = input("Enter file path of the image (without '' or ""): ")
    output_path = input("Enter file path of the output folder (without '' or ""): ")
    imageog = cv2.imread(filepath)

    if imageog is None:
        print("Error: Image not found")
    else:
        # Convert to garyscale and inverting
        gray = cv2.cvtColor(imageog, cv2.COLOR_BGR2GRAY)
        invgray = 255 - gray

        # Applying gaussian blur and inverting
        kernel = input("Enter the kernel size for Gaussian blurring: ")
        if kernel == '':
            kernel = 55
        elif int(kernel) %2 ==0:
            print("Kernel size cannot be even")
            kernel = input("Enter the kernel size for Gaussian blurring: ")
        kernel = int(kernel)
            
        blur = cv2.GaussianBlur(invgray, (kernel, kernel), 0)
        invblur = 255 - blur
        division = ((gray.astype(float)/(invblur.astype(float))+0.01)*255)
        sketch = (np.minimum(255,division)).astype(np.uint8)
        return imageog, sketch, output_path
original, sketch, output_path = main()
display(original, sketch, output_path)
