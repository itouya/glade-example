#include "vclass_server.h"

int main(int argc, char *argv[])
{
    auto vclass_server = VclassServer::create();

    return vclass_server->run(argc, argv);
}
