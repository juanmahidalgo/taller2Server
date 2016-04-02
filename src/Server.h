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
#include "Manager.h"


#include <stdio.h>
#include <string.h>
#include <iostream>


using namespace std;


class Server {
public:
	Server();
	virtual ~Server();
	void init();
	void uninit();
	void update();
	//string readRequestHeader(mg_connection* conn, string header);
	void handleEvent(struct mg_connection* nc, int ev, void* ev_data);
	string login(string user, string password);
	void createUser(Json::Value json);
	void handleCreateUser(struct mg_connection *nc, struct http_message *hm);
	void setManager(Manager* mg);
	Manager* getManager();

private:
	Manager* manager;
	struct mg_mgr mgr;
	struct mg_connection *nc;
	char *s_http_port;


};


static void ev_handler(struct mg_connection* nc, int ev, void* ev_data){
	Server* server = (Server*) nc->mgr->user_data;
	server->handleEvent(nc, ev, ev_data);
}
#endif /* SERVER_H_ */
