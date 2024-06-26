//
// Created by mito on 20.06.2024.
//

#ifndef COLOR_H
#define COLOR_H

#include "SFML/Graphics.hpp"

namespace rumpedav {
    enum class MaterialColor {
        Red, Pink, Purple, DeepPurple, Indigo, Blue, LightBlue, Cyan, Teal, Green, LightGreen, Lime, Yellow, Amber,
        Orange, DeepOrange, Brown, Grey, BlueGrey
    };

    enum class Variant { _50, _100, _200, _300, _400, _500, _600, _700, _800, _900, A100, A200, A400, A700 };

    enum class HtmlColor {
        white, whitesmoke, gainsboro, lightgrey, silver, darkgrey, grey, dimgrey, black, mistyrose, lightcoral, salmon,
        rosybrown, tomato, indianred, red, firebrick, brown, darkred, maroon, seashell, peachpuff, lightsalmon,
        darksalmon, sandybrown, coral, peru, orangered, chocolate, sienna, saddlebrown, snow, floralwhite, oldlace,
        linen, papayawhip, antiquewhite, blanchedalmond, bisque, moccasin, navajowhite, wheat, burlywood, tan,
        darkorange, orange, goldenrod, darkgoldenrod, cornsilk, lemonchiffon, palegoldenrod, khaki, darkkhaki, gold,
        ivory, lightyellow, beige, lightgoldenrodyellow, yellow, olive, greenyellow, yellowgreen, olivedrab,
        darkolivegreen, chartreuse, lawngreen, honeydew, palegreen, lightgreen, darkseagreen, lime, limegreen,
        forestgreen, green, darkgreen, springgreen, mediumseagreen, seagreen, mintcream, aquamarine, mediumaquamarine,
        mediumspringgreen, turquoise, mediumturquoise, lightseagreen, azure, lightcyan, paleturquoise, powderblue,
        lightblue, cyan, cadetblue, darkturquoise, darkcyan, teal, darkslategrey, aliceblue, lightskyblue, skyblue,
        dodgerblue, deepskyblue, steelblue, lightsteelblue, cornflowerblue, royalblue, lightslategrey, slategrey,
        lavender, mediumslateblue, slateblue, blue, mediumblue, darkslateblue, darkblue, midnightblue, navy,
        mediumpurple, ghostwhite, blueviolet, darkorchid, darkviolet, indigo, mediumorchid, thistle, plum, violet,
        orchid, magenta, darkmagenta, purple, deeppink, mediumvioletred, pink, lightpink, crimson, lavenderblush,
        hotpink, palevioletred
    };

    const static unsigned char HtmlColors[][3] = {
        {255, 255, 255}, {245, 245, 245}, {220, 220, 220}, {211, 211, 211}, {192, 192, 192}, {169, 169, 169},
        {128, 128, 128}, {105, 105, 105}, {0, 0, 0}, {255, 228, 225}, {240, 128, 128}, {250, 128, 114}, {188, 143, 143},
        {255, 99, 71}, {205, 92, 92}, {255, 0, 0}, {178, 34, 34}, {165, 42, 42}, {139, 0, 0}, {128, 0, 0},
        {255, 245, 238}, {255, 218, 185}, {255, 160, 122}, {233, 150, 122}, {244, 164, 96}, {255, 127, 80},
        {205, 133, 63}, {255, 69, 0}, {210, 105, 30}, {160, 82, 45}, {139, 69, 19}, {255, 250, 250}, {255, 250, 240},
        {253, 245, 230}, {250, 240, 230}, {255, 239, 213}, {250, 235, 215}, {255, 235, 205}, {255, 228, 196},
        {255, 228, 181}, {255, 222, 173}, {245, 222, 179}, {222, 184, 135}, {210, 180, 140}, {255, 140, 0},
        {255, 165, 0}, {218, 165, 32}, {184, 134, 11}, {255, 248, 220}, {255, 250, 205}, {238, 232, 170},
        {240, 230, 140}, {189, 183, 107}, {255, 215, 0}, {255, 255, 240}, {255, 255, 224}, {245, 245, 220},
        {250, 250, 210}, {255, 255, 0}, {128, 128, 0}, {173, 255, 47}, {154, 205, 50}, {107, 142, 35}, {85, 107, 47},
        {127, 255, 0}, {124, 252, 0}, {240, 255, 240}, {152, 251, 152}, {144, 238, 144}, {143, 188, 143}, {0, 255, 0},
        {50, 205, 50}, {34, 139, 34}, {0, 128, 0}, {0, 100, 0}, {0, 255, 127}, {60, 179, 113}, {46, 139, 87},
        {245, 255, 250}, {127, 255, 212}, {102, 205, 170}, {0, 250, 154}, {64, 224, 208}, {72, 209, 204},
        {32, 178, 170}, {240, 255, 255}, {224, 255, 255}, {175, 238, 238}, {176, 224, 230}, {173, 216, 230},
        {0, 255, 255}, {95, 158, 160}, {0, 206, 209}, {0, 139, 139}, {0, 128, 128}, {47, 79, 79}, {240, 248, 255},
        {135, 206, 250}, {135, 206, 235}, {30, 144, 255}, {0, 191, 255}, {70, 130, 180}, {176, 196, 222},
        {100, 149, 237}, {65, 105, 225}, {119, 136, 153}, {112, 128, 144}, {230, 230, 250}, {123, 104, 238},
        {106, 90, 205}, {0, 0, 255}, {0, 0, 205}, {72, 61, 139}, {0, 0, 139}, {25, 25, 112}, {0, 0, 128},
        {147, 112, 219}, {248, 248, 255}, {138, 43, 226}, {153, 50, 204}, {148, 0, 211}, {75, 0, 130}, {186, 85, 211},
        {216, 191, 216}, {221, 160, 221}, {238, 130, 238}, {218, 112, 214}, {255, 0, 255}, {139, 0, 139}, {128, 0, 128},
        {255, 20, 147}, {199, 21, 133}, {255, 192, 203}, {255, 182, 193}, {220, 20, 60}, {255, 240, 245},
        {255, 105, 180}, {219, 112, 147}
    };

    // Source: https://materialui.co/colors
    const static unsigned char MaterialColors[][3] = {
        // Red
        {255, 235, 238}, {255, 205, 210}, {239, 154, 154}, {229, 115, 115}, {239, 83, 80}, {244, 67, 54}, {229, 57, 53},
        {211, 47, 47}, {198, 40, 40}, {183, 28, 28}, {255, 138, 128}, {255, 82, 82}, {255, 23, 68}, {213, 0, 0},
        // Pink
        {252, 228, 236}, {248, 187, 208}, {244, 143, 177}, {240, 98, 146}, {236, 64, 122}, {233, 30, 99}, {216, 27, 96},
        {194, 24, 91}, {173, 20, 87}, {136, 14, 79}, {255, 128, 171}, {255, 64, 129}, {245, 0, 87}, {197, 17, 98},
        // Purple
        {243, 229, 245}, {225, 190, 231}, {206, 147, 216}, {186, 104, 200}, {171, 71, 188}, {156, 39, 176},
        {142, 36, 170}, {123, 31, 162}, {106, 27, 154}, {74, 20, 140}, {234, 128, 252}, {224, 64, 251}, {213, 0, 249},
        {170, 0, 255},
        // DeepPurple
        {237, 231, 246}, {209, 196, 233}, {179, 157, 219}, {149, 117, 205}, {126, 87, 194}, {103, 58, 183},
        {94, 53, 177}, {81, 45, 168}, {69, 39, 160}, {49, 27, 146}, {140, 158, 255}, {124, 77, 255}, {101, 31, 255},
        {98, 0, 234},
        // Indigo
        {232, 234, 246}, {197, 202, 233}, {159, 168, 218}, {121, 134, 203}, {92, 107, 192}, {63, 81, 181},
        {57, 73, 171}, {48, 63, 159}, {40, 53, 147}, {26, 35, 126}, {140, 158, 255}, {83, 109, 254}, {61, 90, 254},
        {48, 79, 254},
        // Blue
        {227, 242, 253}, {187, 222, 251}, {144, 202, 249}, {79, 195, 247}, {66, 165, 245}, {63, 81, 181},
        {30, 136, 229}, {25, 118, 210}, {21, 101, 192}, {13, 71, 161}, {130, 177, 255}, {68, 138, 255}, {41, 121, 255},
        {41, 98, 255},
        // LightBlue
        {225, 245, 254}, {179, 229, 252}, {129, 212, 250}, {79, 195, 247}, {41, 182, 246}, {3, 169, 244}, {3, 155, 229},
        {2, 136, 209}, {2, 119, 189}, {1, 87, 155}, {128, 216, 255}, {64, 196, 255}, {0, 176, 255}, {0, 145, 234},
        // Cyan
        {224, 247, 250}, {178, 235, 242}, {128, 222, 234}, {77, 208, 225}, {38, 198, 218}, {0, 188, 212}, {0, 172, 193},
        {0, 151, 167}, {0, 131, 143}, {0, 96, 100}, {132, 255, 255}, {24, 255, 255}, {0, 229, 255}, {0, 184, 212},
        // Teal
        {224, 242, 241}, {178, 223, 219}, {128, 203, 196}, {77, 182, 172}, {38, 166, 154}, {0, 150, 136}, {0, 137, 123},
        {0, 121, 107}, {0, 105, 92}, {0, 77, 64}, {167, 255, 235}, {100, 255, 218}, {29, 233, 182}, {0, 191, 165},
        // Green
        {232, 245, 233}, {200, 230, 201}, {165, 214, 167}, {129, 199, 132}, {102, 187, 106}, {76, 175, 80},
        {67, 160, 71}, {56, 142, 60}, {46, 125, 50}, {27, 94, 32}, {185, 246, 202}, {105, 240, 174}, {0, 230, 118},
        {0, 200, 83},
        // LightGreen
        {241, 248, 233}, {220, 237, 200}, {197, 225, 165}, {174, 213, 129}, {156, 204, 101}, {139, 195, 74},
        {124, 179, 66}, {104, 159, 56}, {85, 139, 47}, {51, 105, 30}, {204, 255, 144}, {178, 255, 89}, {118, 255, 3},
        {100, 221, 23},
        // Lime
        {249, 251, 231}, {240, 244, 195}, {230, 238, 156}, {220, 231, 117}, {212, 225, 87}, {205, 220, 57},
        {192, 202, 51}, {175, 180, 43}, {158, 157, 36}, {130, 119, 23}, {130, 119, 23}, {238, 255, 65}, {198, 255, 0},
        {174, 234, 0},
        // Yellow
        {255, 253, 231}, {255, 249, 196}, {255, 245, 157}, {255, 241, 118}, {255, 238, 88}, {255, 235, 59},
        {253, 216, 53}, {251, 192, 45}, {249, 168, 37}, {245, 127, 23}, {255, 255, 141}, {255, 255, 0}, {255, 234, 0},
        {255, 214, 0},
        // Amber
        {255, 248, 225}, {255, 236, 179}, {255, 224, 130}, {255, 213, 79}, {255, 202, 40}, {255, 193, 7}, {255, 179, 0},
        {255, 160, 0}, {255, 143, 0}, {255, 111, 0}, {255, 229, 127}, {255, 215, 64}, {255, 196, 0}, {255, 171, 0},
        // Orange
        {255, 243, 224}, {255, 224, 178}, {255, 204, 128}, {255, 183, 77}, {255, 167, 38}, {255, 152, 0}, {251, 140, 0},
        {245, 124, 0}, {239, 108, 0}, {230, 81, 0}, {255, 209, 128}, {255, 171, 64}, {255, 145, 0}, {255, 109, 0},
        // DeepOrange
        {251, 233, 231}, {255, 204, 188}, {255, 171, 145}, {255, 138, 101}, {255, 112, 67}, {255, 87, 34},
        {244, 81, 30}, {230, 74, 25}, {216, 67, 21}, {191, 54, 12}, {255, 158, 128}, {255, 110, 64}, {255, 61, 0},
        {221, 44, 0},
        // Brown
        {239, 235, 233}, {215, 204, 200}, {188, 170, 164}, {161, 136, 127}, {141, 110, 99}, {121, 85, 72},
        {109, 76, 65}, {93, 64, 55}, {78, 52, 46}, {62, 39, 35}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255},
        {255, 255, 255},
        // Grey
        {250, 250, 250}, {245, 245, 245}, {238, 238, 238}, {224, 224, 224}, {189, 189, 189}, {158, 158, 158},
        {117, 117, 117}, {97, 97, 97}, {66, 66, 66}, {33, 33, 33}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255},
        {255, 255, 255},
        // BlueGrey
        {236, 239, 241}, {207, 216, 220}, {176, 190, 197}, {144, 164, 174}, {120, 144, 156}, {96, 125, 139},
        {84, 110, 122}, {69, 90, 100}, {55, 71, 79}, {38, 50, 56}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255},
        {255, 255, 255}
    };

    class Color {
        unsigned char r = 255;
        unsigned char g = 255;
        unsigned char b = 255;
        unsigned char a = 255;
    public:
        Color() : r(0), g(0), b(0), a(255) {

        }

        Color(unsigned char _r, unsigned char _g, unsigned char _b)
        : r(_r), g(_g), b(_b), a(255) {

        }

        static sf::Color Material(MaterialColor materialColor, Variant variant) {
            const unsigned char *color = MaterialColors[
                14 * static_cast<unsigned int>(materialColor) + static_cast<unsigned int>(variant)];
            return {color[0], color[1], color[2]};
        }

        static sf::Color HTML(HtmlColor htmlColor) {
            const unsigned char *color = HtmlColors[static_cast<unsigned int>(htmlColor)];
            return {color[0], color[1], color[2]};
        }
    };
}

#endif //COLOR_H
