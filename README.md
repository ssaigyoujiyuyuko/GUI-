# GUI-
一个简易的酒店管理系统(文件)
QStackedLayout：堆栈布局，是将一堆widget控件放置在一起，只有一个控件是能看见的。
其不是管理控件的尺寸即位置，而是尺寸的显示，可以被一些字窗口控件（页）在同一空间填充。多用于页面切换等的操作。
但是QStackedWidget并没有提供一种方法给用户区切换页。
这种方式就需要借助QComboBox或者QListWidget去存储每个页面的标题，从而配合实现切换页面。
当填充布局的时候，窗口部件widget会加载到内部的一个列表中，通过indexOf()方法返回一个窗口部件widge的索引在内部的列表中。当然widget可以被添加到列表的末尾，或者插入到指定的索引位置。removeWidget()方法删除在索引序号为index的窗口部件。
通过count()方法可以获取到加载到布局layout的元素个数。
widget()方法返回在指定位置上的部件widget,当前屏幕上显示的的窗口部件的索引序号值可以用使用currentIndex()获取，并且使用setCurrentIndex()设置。
相似的情况，当前的显示可见的窗口部件可以通过currentWidget获取到，使用setCurrentWidget（）更新。
但是不管什么情况，只要当前widget的布局变了或者remove删除，则currentChanged()信号和widgetRemoved（）信号会一次发送。
