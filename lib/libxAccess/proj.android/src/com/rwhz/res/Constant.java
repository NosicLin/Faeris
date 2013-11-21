package com.rwhz.res;

/**
 * �?��的常量定�? * 原则上代码中不允许出现魔术数，所有公共类的常量都在此定义�? * 字符串全部集中在此，将来变更其它语种时可以统�?��整�?
 * @author Bingle
 *
 */
public class Constant { 
	public final static int HTTP_ClientProtocolException = 503;
	public final static String HTTP_ClientProtocolExceptionMessage="HTTP_ClientProtocolException";
	public final static int HTTP_IOException=504;
	public final static String HTTP_IOExceptionMessage="HTTP_IOException";
	public final static int HTTP_ParseException=505;
	public final static String HTTP_ParseExceptionMessage="HTTP_ParseException";
	public final static int HTTP_CRCException=506;
	public final static String HTTP_CRCExceptionMessage="HTTP_CRCException";
	public final static int HTTP_IllegalStateException=507;
	public final static String HTTP_IllegalStateExceptionMessage="HTTP_CRCException";
	public final static int HTTP_GeneralException=509;
	public final static String HTTP_GeneralExceptionMessage="HTTP_GeneralExceptionMessage";
	
	public final static int SOCKET_CONNECT_UnknownHostException=511;
	public final static String SOCKET_CONNECT_UnknownHostExceptionMessage="SOCKET_CONNECT_UnknownHostException";
	public final static int SOCKET_CONNECT_IOException=512;
	public final static String SOCKET_CONNECT_IOExceptionMessage="SOCKET_CONNECT_IOException";
	public final static int SOCKET_SEND_SocketStatusNotReady=513;
	public final static String SOCKET_SEND_SocketStatusNotReadyMessage="SOCKET_SEND_SocketStatusNotReady";
	public final static int SOCKET_SEND_IOException=514;
	public final static String SOCKET_SEND_IOExceptionMessage="SOCKET_SEND_IOException";
	public final static int SOCKET_GeneralException=519;
	public final static String SOCKET_GeneralExceptionMessage="SOCKET_GeneralExceptionMessage";

	public final static int PARSE_GeneralException=599;
	public final static String PARSE_GeneralExceptionMessage="PARSE_GeneralExceptionMessage";
}
