/*
 * Server.h
 *
 *  Created on: Mar 26, 2016
 *      Author: juanma
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "mongoose.h"
#include "HttpRequest.h"
#include "HttpRequestHandler.h"




class Server {
public:
	Server();
	virtual ~Server();
	void init();
	void uninit();
	void update();
	void handleEvent(struct mg_connection* nc, int ev, void* ev_data);


private:
	struct mg_mgr mgr;
	struct mg_connection *nc;
	char *s_http_port;


};

static Server* serverConnection;

static void ev_handler(struct mg_connection* nc, int ev, void* ev_data){
	serverConnection->handleEvent(nc, ev, ev_data);
}
#endif /* SERVER_H_ */
