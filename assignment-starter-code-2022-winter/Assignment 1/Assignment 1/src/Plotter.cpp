#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    double x0 = 0, y0 = 0;
    double x1 = 0, y1 = 0;
    PenStyle style = { 1, "black" };
    bool pen = false;
    for (string line; getline(input, line); ) {
        line = toLowerCase(line);
        Vector<string> factor = stringSplit(line, " ");
        if (factor[0] == "pendown") {
            pen = true;
        } else if (factor[0] == "penup") {
            pen = false;
        } else if (factor[0] == "moveabs") {
            if (pen){
                x1 = stringToReal(factor[1]);
                y1 = stringToReal(factor[2]);
                drawLine(x0, y0, x1, y1, style);
                x0 = x1;
                y0 = y1;
            } else {
                x0 = stringToReal(factor[1]);
                y0 = stringToReal(factor[2]);
            }
        } else if (factor[0] == "moverel") {
            if (pen){
                x1 = x0 + stringToReal(factor[1]);
                y1 = y0 + stringToReal(factor[2]);
                drawLine(x0, y0, x1, y1, style);
                x0 = x1;
                y0 = y1;
            } else {
                x0 += stringToReal(factor[1]);
                y0 += stringToReal(factor[2]);
            }
        } else if (factor[0] == "pencolor") {
            style.color = factor[1];
        } else if (factor[0] == "penwidth") {
            style.width = stringToReal(factor[1]);
        }
        factor.clear();
    }

}
