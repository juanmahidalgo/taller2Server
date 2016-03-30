/*
 * HttpRequestHandler.cpp
 *
 *  Created on: 26/03/2016
 *      Author: demian
 */

#include "HttpRequestHandler.h"

#include <iostream>

HttpRequestHandler::HttpRequestHandler() {


}

HttpRequestHandler::~HttpRequestHandler() {
	// TODO Auto-generated destructor stub
}

void HttpRequestHandler::proccesRequest(HttpRequest& httpRequest){
	std::cout<<"Method: "<<httpRequest.getMethod()<<std::endl;
	std::cout<<"Uri: "<<httpRequest.getUri()<<std::endl;
	std::cout<<"Body: "<<httpRequest.getBody()<<std::endl;
}
