
import cv2
import mediapipe as mp
from cvzone.FaceDetectionModule import FaceDetector
import serial


cap = cv2.VideoCapture(0)
 
detector = FaceDetector(minDetectionCon=0.6)

arduinoSerialData = serial.Serial('com5',9600)

while(cap.isOpened()):
    ret, img = cap.read()
    if ret==True:
            
            img, bboxes = detector.findFaces(img)

            if bboxes:
        
                arduinoSerialData.write(b'Y') #Send H to the arduino to take the required actions 
        
            else:
         
                arduinoSerialData.write(b'N') #Send L to the arduino to be on hold position
            
            cv2.imshow("Image",img)
            if cv2.waitKey(1) & 0xFF == ord('q'): #Press Button "Q/q" to exit the window
                break
            
    else:
        break
cap.release()
cv2.destroyAllWindows()
                          