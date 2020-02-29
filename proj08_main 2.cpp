//Nate Wood

#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;
#include<fstream>
using std::ifstream; using std::ofstream;
#include "proj08-struct.h"
//int main(int, char **argv) {
//
//    using namespace std::literals;
//
//    /*
//     ./a.out 4 test.pgm
//     argv[1] is the case number
//     argv[2] is the name of a .pgm file
//     argv[3] (when present) is also a .pgm file
//     */
//    switch (std::stoi(argv[1])) {
//        case 1: {
//            Image im(argv[2]);
//            im.write_image("same_"s + argv[2]);
//            break;
//        }
//        case 2:{
//            Image im(argv[2]);
//            auto sh_im = im.sharpen();
//            sh_im.write_image("sharpen_"s + argv[2]);
//            break;
//        }
//        case 3:{
//            Image im(argv[2]);
//            auto bl_im = im.blur();
//            bl_im.write_image("blur_"s + argv[2]);
//            break;
//        }
//        case 4:{
//            Image im(argv[2]);
//            auto ed_im = im.edge_detect();
//            ed_im.write_image("edge_detect"s + argv[2]);
//            break;
//        }
//        case 5:{
//            Image im(argv[2]);
//            auto em_im = im.edge_detect();
//            em_im.write_image("emboss_"s + argv[2]);
//            break;
//        }
//        case 6:{
//            Image im(argv[2]);
//            Image secret(argv[3]);
//            im.embed(secret);
//            im.write_image("embedded_"s + argv[2]);
//            auto hid = im.extract(200);
//            hid.write_image("extracted_"s + argv[2]);
//            break;
//        }
//    } // of switch
//} // of main
/*
 Image test("test.pgm");
 auto image_test = test.sharpen();
 image_test.write_image("temp.pgm");
 
 Image columns("columns.ascii.pgm");
 image_test = columns.sharpen();
 image_test.write_image("columns_sharp.pgm");
 image_test = columns.edge_detect();
 image_test.write_image("columns_edge_detect.pgm");
 image_test = columns.blur();
 image_test.write_image("columns_blurry.pgm");
 image_test = columns.emboss();
 image_test.write_image("columns_embossed.pgm");
 Image test("dragon.pgm");
 Image columns("columns.ascii.pgm");
 columns.embed(test);
 columns.write_image("hidden.pgm");
 
 Image hid("hidden.pgm");
 auto secret = hid.extract(200);
 secret.write_image("unhidden.pgm");
 }
 */
int main(){
    Image ans;
    ans.width_ = 5;
    ans.height_ = 5;
    ans.max_val_ = 245;
    ans.pixels_ = {{1, 2, 3, 4, 5},{6, 7, 8, 9, 10},{11, 12, 13, 14, 15},{16, 17, 18, 19, 20},{21, 22, 23, 24, 25}};
    ans.write_image("new.pgm");
    string s;
    ifstream file ("new.pgm");
    while (getline(file, s)){
        cout << s << endl;
    }
    Image x("new.pgm");
    //cout << x.width_ << endl;
    //cout << x.height_ << endl;
    //cout << x.max_val_ << endl;
    for (auto line : x.pixels_){
        for (auto c : line){
            cout << c << " ";
        }
        cout << endl;
    }
}
