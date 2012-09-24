/*
 * @file HttpRequest.h
 * @brief http request data packet
 *
 * @version 1.0
 * @date Sat Sep 15 00:15:11 2012
 *
 * @copyright Copyright (C) 2012 UESTC
 * @author shiwei<shiwei2012@gmail.com>
 */

#ifndef http_HttpRequest_H_
#define http_HttpRequest_H_

#include <map>
#include <string>


namespace ossfs
{


class HttpRequest
{
public:
    // method
    static const std::string OPTIONS;
    static const std::string HEAD;
    static const std::string GET;
    static const std::string POST;
    static const std::string PUT;
    static const std::string DELETE;
    static const std::string TRACE;
    static const std::string CONNECT;

    // version
    static const std::string HTTP_VERSION_11;

public:
    HttpRequest();

    virtual ~HttpRequest();

    /**
     * @brief set http request method, PUT, GET, POST, HEAD, etc
     *
     * @param method
     */
    inline void setMethod(const std::string &method);

    inline const std::string &getMethod() const;

    /**
     * @brief set request uri
     *
     * @param uri
     */
    inline void setURI(const std::string &uri);

    inline const std::string &getURI() const;

    /**
     * @brief set http version string, default "HTTP/1.1"
     *
     * @param version
     */
    inline void setVersion(const std::string &version);

    inline const std::string &getVersion() const;

    /**
     * @brief has parameter "paramName"?
     *
     * @param paramName
     *
     * @return
     */
    bool hasParameter(const std::string &paramName) const;

    /**
     * @brief add a request parameter if not exists,
     *          or replace it with new value
     *
     * @param name
     * @param
     */
    void setParameter(
        const std::string &name,
        const std::string &value
    );

    std::string getParameter(const std::string &name) const;

    /**
     * @brief has http header "name"?
     *
     * @param name
     *
     * @return
     */
    bool hasHeader(const std::string &name) const;

    /**
     * @brief add a http header if not exists,
     *          or replace it with new value
     *
     * @param name
     * @param
     */
    void setHeader(
        const std::string &name,
        const std::string &value
    );

    std::string getHeader(const std::string &name) const;

    /**
     * @brief set request body, if there's already a body,
     *          replace it with new data
     *
     * @param body
     */
    inline void setBody(const std::string &body);

    /**
     * @brief append more data to request body
     *
     * @param data
     */
    inline void appendBody(const std::string &data);

    inline const std::string &getBody() const;

    /**
     * @brief parse http request structure from raw data string
     *
     * @param data
     *
     * @return 
     */
    bool parseFromString(const std::string &data);

    /**
     * @brief serialize current http request to data stream
     *
     * @param data
     *
     * @return 
     */
    bool serializeToString(std::string *data) const;

protected:
    std::string _method;
    std::string _uri;
    std::string _version;

    std::map<std::string, std::string> _params;
    std::map<std::string, std::string> _headers;

    std::string _body;
};


void
HttpRequest::setMethod(const std::string &method)
{
    _method = method;
}

const std::string &
HttpRequest::getMethod() const
{
    return _method;
}

void
HttpRequest::setURI(const std::string &uri)
{
    _uri = uri;
}

const std::string &
HttpRequest::getURI() const
{
    return _uri;
}

void
HttpRequest::setVersion(const std::string &version)
{
    _version = version;
}

const std::string &
HttpRequest::getVersion() const
{
    return _version;
}

void
HttpRequest::setBody(const std::string &body)
{
    _body = body;
}

void
HttpRequest::appendBody(const std::string &data)
{
    _body.append(data);
}

const std::string &
HttpRequest::getBody() const
{
    return _body;
}


}


#endif  // http_HttpRequest_H_

