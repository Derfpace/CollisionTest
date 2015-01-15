#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

class Render {
    public:
        static void renderBox(int posx, int posy, int poswidth, int posheight, float colorRed, float colorGreen, float colorBlue);
        Render();
        virtual ~Render();
};
#endif // RENDER_H_INCLUDED
