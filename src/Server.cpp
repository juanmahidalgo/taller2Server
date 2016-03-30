/*
 * Server.cpp
 *
 *  Created on: Mar 26, 2016
 *      Author: juanma
 */

#include "Server.h"

static struct mg_serve_http_opts s_http_server_opts;

Server::Server() {
	this->s_http_port = "8000";
}

Server::~Server() {
	  mg_mgr_free(&mgr);
}


void Server::init(){
	mg_mgr_init(&mgr, NULL);
	nc = mg_bind(&mgr, "8000", ev_handler);
	mg_set_protocol_http_websocket(nc);
}


void Server::uninit(){
	mg_mgr_free(&mgr);
}

void Server::update(){
	mg_mgr_poll(&mgr, 1000);
}


void Server::handleEvent(struct mg_connection* nc, int ev, void* ev_data){
		struct http_message *hm = (struct http_message *) ev_data;

		switch(ev){
		case MG_EV_HTTP_REQUEST: {
			HttpRequest request(hm);
			HttpRequestHandler requestHandler;
			requestHandler.proccesRequest(request);
			//DEVUELVE TEXTO PLANO!
			mg_printf(nc, "HTTP/1.1 200 OK\r\n"
	                "Content-Type: text/plain\r\n"
	                "Content-Length: 21\r\n\r\n"
			"{ User : \"Username\" }");
			break;
			}
		default:
			break;
		}
}
