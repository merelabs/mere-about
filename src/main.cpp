#include "mereaboutapp.h"

int main(int argc, char *argv[])
{
    MereAboutApp app(argc, argv);
    app.init();
    app.start();
    return app.exec();
}
