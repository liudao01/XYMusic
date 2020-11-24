
#ifndef MYMUSIC_ANDROIDLOG_H
#define MYMUSIC_ANDROIDLOG_H


#include "android/log.h"

#define LOG_DEBUG true //日志开关，true为开，其它为关
#define TAG "jniLib"//标签

#define LOGD(FORMAT,...) if(LOG_DEBUG) __android_log_print(ANDROID_LOG_DEBUG,TAG,FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT,...) if(LOG_DEBUG) __android_log_print(ANDROID_LOG_ERROR,TAG,FORMAT,##__VA_ARGS__);

#endif //MYMUSIC_ANDROIDLOG_H
