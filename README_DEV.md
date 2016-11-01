Implementation of frame functionality:

I was thinking we could just create another custom form and show it when the user clicks on the play button or from the file menu.
we would need to send the current image at that time, in case it hasn't been updated yet. 
void Controller::receiveButtonInput(QWidget * child) <<--- this is the method where all the button events are handled. 

Then every time the user makes an edit ( or wherever we emit Controller::sendImage() ) we update the preview as well.

As for the frames themselves we just need an API to access the frameset from the Project attribute in controller. Class methods etc.

<-------feel free to make edits to this above or suggestions below--------

