import sys
from PyQt5 import QtCore, QtWidgets
from PyQt5.QtWidgets import QMainWindow, QLabel, QCheckBox, QWidget
from PyQt5.QtCore import QSize    
import mygameengine

class MainWindow(QtWidgets.QWidget):

    switch_window = QtCore.pyqtSignal(str)

    def __init__(self):
        QtWidgets.QWidget.__init__(self)
        self.setWindowTitle('Game Engine')

        layout = QtWidgets.QGridLayout()
        self.setMinimumSize(QSize(500, 500))    

        
        self.labelFilePath = QLabel('Tile Sprite:', self)
        self.labelFilePath.move(20,60)
        self.line_edit = QtWidgets.QLineEdit()
        layout.addWidget(self.line_edit)


        # print(text)
        self.labelHeight = QLabel('Level Height', self)
        self.labelHeight.move(20,165)
        self.line_edit1 = QtWidgets.QLineEdit()
        layout.addWidget(self.line_edit1)
        print(self.line_edit1.text)
        
        self.labelWidth = QLabel('Level Width', self)
        self.labelWidth.move(20,265)
        self.line_edit2 = QtWidgets.QLineEdit()
        layout.addWidget(self.line_edit2)
        print(self.line_edit2.text)


        self.button = QtWidgets.QPushButton('Generate!')
        self.button.clicked.connect(self.switch)
        layout.addWidget(self.button)

        self.setLayout(layout)

    def switch(self):
        test.setInit(int(self.line_edit1.text()),int(self.line_edit2.text()),self.line_edit.text())
        self.switch_window.emit(self.line_edit.text())
        self.switch_window.emit(test.Loop())



class WindowTwo(QtWidgets.QWidget):

    def __init__(self, text):

        # print(text)
        QtWidgets.QWidget.__init__(self)
        self.setMinimumSize(QSize(140, 200))    
        self.setWindowTitle("Checkbox") 

        self.b = QCheckBox("Input?",self)
        self.b.setChecked(test.getPlayable())
        # self.b.setChecked(test.getPlayable())

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
        self.button = QtWidgets.QPushButton('PyQt5 button')
        self.button.setToolTip('This is an example button')
        self.button.move(20,130)
        # self.button.clicked.connect(True)
        # self.value=test.gridSelected()
        # print(self.value)
        # self.button = QtWidgets.QPushButton('Generate!')
        # self.button.clicked.connect(self.switch)
 
#  .
    def switch(self):
        self.switch_window.emit(self.line_edit.text())


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
        # self.setWindowTitle('Window Two')

        # layout = QtWidgets.QGridLayout()

        # self.label = QtWidgets.QLabel(text)
        # layout.addWidget(self.label)

        # self.button = QtWidgets.QPushButton('Close')
        # self.button.clicked.connect(self.close)

        # layout.addWidget(self.button)

        # self.setLayout(layout)


class Login(QtWidgets.QWidget):

    switch_window = QtCore.pyqtSignal()

    def __init__(self):
        QtWidgets.QWidget.__init__(self)
        self.setMinimumSize(QSize(300, 300))    

        self.setWindowTitle('Game Engine')

        layout = QtWidgets.QGridLayout()
        self.label = QLabel('Platformer', self)
        self.label.move(80,60)
        self.label2 = QLabel('Engine', self)
        self.label2.move(80,80)


        self.button = QtWidgets.QPushButton('Continue')
        self.button.clicked.connect(self.login)

        layout.addWidget(self.button)

        self.setLayout(layout)

    def login(self):
        self.switch_window.emit()


class Controller:

    def __init__(self):
        pass

    def show_login(self):
        self.login = Login()
        self.login.switch_window.connect(self.show_main)
        self.login.show()

    def show_main(self):
        self.window = MainWindow()
        self.window.switch_window.connect(self.show_window_two)
        self.login.close()
        self.window.show()

    def show_window_two(self, text):
        self.window_two = WindowTwo(text)
        self.window.close()
        self.window_two.show()


def main():
    app = QtWidgets.QApplication(sys.argv)
    controller = Controller()
    controller.show_login()
    sys.exit(app.exec_())



if __name__ == '__main__':
    test = mygameengine.Engine()

    main()
