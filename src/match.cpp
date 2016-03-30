/*
 * Copyright (c) 2014 Cesanta Software Limited
 * All rights reserved
 */

#include "mongoose.h"
#include "Server.h"
#include <iostream>
using namespace std;


static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;

int main(int argc, char *argv[]) {
	Server* serv = new Server();
	serv->init();
	for (;;) {
		serv->update();
	}
	std::cout<<"End"<<std::endl;

	return 0;
}
