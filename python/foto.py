import cv2
from pynput.keyboard import Key, Controller

cam = cv2.VideoCapture(0)

cv2.namedWindow("test")

img_counter = 0

while True:
    ret, frame = cam.read()
    cv2.imshow("test", frame)
    #Keyboard = Controller()
    #Keyboard.press(Key.space) solo se vuoi salvare foto all'infinito//only to save infinite photo with press space
    if not ret:
        break
    x = cv2.waitKey(1)

    if x%256 == 27:
        # ESC pressed
        print("closing...")
        break
    elif x%256 == 32:
        # SPACE pressed
        img_name = "opencv_frame_{}.png".format(img_counter)
        cv2.imwrite(img_name, frame)
        print("{} written!".format(img_name))
        img_counter += 1

cam.release()

cv2.destroyAllWindows()
