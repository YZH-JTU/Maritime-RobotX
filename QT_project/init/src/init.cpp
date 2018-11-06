#include "../../globalvar/inc/globalvar.h"
#include "../../socket/inc/pack_unpack.h"
#include "../../socket/inc/server.h"
#include <thread>
#include <unistd.h>

void init_sys(void){
    std::thread _thread_socket_accept_PLC(startup_socket_PLC);
    _thread_socket_accept_PLC.detach();
    std::thread _thread_socket_accept_MONITOR(startup_socket_MONITOR);
    _thread_socket_accept_MONITOR.detach();
}
