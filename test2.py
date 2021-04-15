import sys
from PyQt5 import QtCore, QtWidgets
from PyQt5.QtWidgets import QMainWindow, QLabel, QCheckBox, QWidget
from PyQt5.QtCore import QSize    
import mygameengine
currentTile=0
class ExampleWindow(QMainWindow):

    def __init__(self):
        QMainWindow.__init__(self)

        self.setMinimumSize(QSize(140, 140))    
        self.setWindowTitle("Checkbox") 

        self.b = QCheckBox("Input?",self)
        self.b.setChecked(test.getPlayable())
        self.b.setChecked(test.getPlayable())

        # print(test.gridSelected())
        self.b.stateChanged.connect(self.pyInput)
        self.b.move(20,20)
        self.c = QCheckBox("Gravity?",self)
        self.c.stateChanged.connect(self.pyGravity)
        # self.b.resize(320,40)
        self.c.move(20,40)
        # self.c.resize(320,40)
        self.d = QCheckBox("Collidable?",self)
        self.d.stateChanged.connect(self.pyCollidable)
        self.d.move(20,60)
        self.e = QCheckBox("Collectable?",self)
        self.e.stateChanged.connect(self.pyCollectable)
        self.e.move(20,80)
        self.f = QCheckBox("AI?",self)
        self.f.stateChanged.connect(self.pyAI)
        self.f.move(20,100)
        # print("HI"+test.getGridNumber())

    def pyInput(self,state):
        test.Playable()
    def pyGravity(self,state):
        test.Gravity()
    def pyCollidable(self,state):
        test.Collidable()
    def pyCollectable(self,state):
        test.Collectable()
    def pyAI(self,state):
        test.AI()
    def default(self):
        print(test.gridNumber)
  



    # def clickBox(self, state):
    

    #     if state == QtCore.Qt.Checked:

    #         print('Checked')
    #     else:
    #         print('Unchecked')
    #     test.Playable()
    # def clickBox1(self, state):
    #     test.Gravity()

        # if state == QtCore.Qt.Checked:

        #     print('Checked')
        # else:
        #     print('Unchecked')
        # QWidgets.QCoreApplication.processEvents()

if __name__ == "__main__":
        #    QCoreApplication.processEvents()


    app = QtWidgets.QApplication(sys.argv)
    test = mygameengine.Engine()
    
    
    mainWin = ExampleWindow()
    mainWin.show()
    test.Loop()
    print(test.gridSelected)
    sys.exit( app.exec_() )