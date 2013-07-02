
http=HttpEngine:create()


request=HttpRequest:create()
request:setUrl("192.168.1.3")
request:addHeader("linux=fsdf")

request.data={                      
	onReponse=function(code,data,err) 
		print("data"..data)
		--f_utillog("code=%d,data=%s,err=%s",code,data,err);
	end
}
                                                                                  
                                                                                 

http:send(request)
