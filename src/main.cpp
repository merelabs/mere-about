#include "aboutapp.h"

int main(int argc, char *argv[])
{
    AboutApp app(argc, argv);
    app.init();
    app.start();
    return app.exec();
}
