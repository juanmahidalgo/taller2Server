/*
 * HttpRequestHandler.h
 *
 *  Created on: 26/03/2016
 *      Author: demian
 */

#ifndef HTTPREQUESTHANDLER_H_
#define HTTPREQUESTHANDLER_H_

#include "HttpRequest.h"

class HttpRequestHandler {
public:
	HttpRequestHandler();
	virtual ~HttpRequestHandler();

	void proccesRequest(HttpRequest& httpRequest);

};

#endif /* HTTPREQUESTHANDLER_H_ */
