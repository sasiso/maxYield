#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_JPEG_Image.H>
#include <opencv2/opencv.hpp>

// Function to convert OpenCV image to FLTK image
Fl_RGB_Image* cvMatToFlRgbImage(const cv::Mat& mat) {
    if (mat.empty()) return nullptr;

    cv::Mat mat_rgb;
    cv::cvtColor(mat, mat_rgb, cv::COLOR_BGR2RGB);
    return new Fl_RGB_Image(mat_rgb.data, mat_rgb.cols, mat_rgb.rows, 3);
}

// Callback function to open and display an image
void open_and_display_image(Fl_Widget *w, void *data) {
    char *filename = fl_file_chooser("Open File", "*.jpg", NULL);
    if (filename != nullptr) {
        cv::Mat img = cv::imread(filename);
        if (!img.empty()) {
            Fl_Box *box = static_cast<Fl_Box*>(data);
            Fl_RGB_Image *fl_img = cvMatToFlRgbImage(img);
            box->image(fl_img->copy(box->w(), box->h()));
            box->redraw();
            delete fl_img; // Avoid memory leaks
        }
    }
}

int main(int argc, char **argv) {
    Fl_Window *window = new Fl_Window(800, 600, "FLTK and OpenCV Example");

    Fl_Box *box = new Fl_Box(10, 10, 780, 540);

    Fl_Button *button = new Fl_Button(10, 560, 780, 30, "Open Image");
    button->callback(open_and_display_image, box);

    window->end();
    window->show(argc, argv);
    return Fl::run();
}
