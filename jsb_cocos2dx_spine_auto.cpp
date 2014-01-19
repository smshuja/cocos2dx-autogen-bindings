#include "jsb_cocos2dx_spine_auto.hpp"
#include "cocos2d_specifics.hpp"
#include "spine-cocos2dx.h"

template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	TypeTest<T> t;
	T* cobj = new T();
	cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
	if (_ccobj) {
		_ccobj->autorelease();
	}
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	assert(p);
	JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
	js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
	JS_AddObjectRoot(cx, &pp->obj);
	JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

	return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	return JS_FALSE;
}


JSClass  *jsb_CCSkeleton_class;
JSObject *jsb_CCSkeleton_prototype;

JSBool js_cocos2dx_spine_CCSkeleton_draw(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->draw();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_setSlotsToSetupPose(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->setSlotsToSetupPose();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_setOpacityModifyRGB(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setOpacityModifyRGB(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_setBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		cocos2d::_ccBlendFunc arg0;
		#pragma warning NO CONVERSION TO NATIVE FOR _ccBlendFunc;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setBlendFunc(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_setToSetupPose(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->setToSetupPose();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_update(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->update(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_getAttachment(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		const char* arg0;
		const char* arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		Attachment* ret = cobj->getAttachment(arg0, arg1);
		jsval jsret;
		#pragma warning NO CONVERSION FROM NATIVE FOR Attachment*;
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_setAttachment(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		const char* arg0;
		const char* arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		bool ret = cobj->setAttachment(arg0, arg1);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_getBlendFunc(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cocos2d::_ccBlendFunc ret = cobj->getBlendFunc();
		jsval jsret;
		#pragma warning NO CONVERSION FROM NATIVE FOR _ccBlendFunc;
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_setSkin(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		bool ret = cobj->setSkin(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_findSlot(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		Slot* ret = cobj->findSlot(arg0);
		jsval jsret;
		#pragma warning NO CONVERSION FROM NATIVE FOR Slot*;
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_updateWorldTransform(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->updateWorldTransform();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_boundingBox(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cocos2d::CCRect ret = cobj->boundingBox();
		jsval jsret;
		jsret = ccrect_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_setBonesToSetupPose(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->setBonesToSetupPose();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_findBone(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		Bone* ret = cobj->findBone(arg0);
		jsval jsret;
		#pragma warning NO CONVERSION FROM NATIVE FOR Bone*;
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_isOpacityModifyRGB(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeleton* cobj = (cocos2d::extension::CCSkeleton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isOpacityModifyRGB();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_createWithFile(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	
	do {
		if (argc == 2) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			cocos2d::extension::CCSkeleton* ret = cocos2d::extension::CCSkeleton::createWithFile(arg0, arg1);
			jsval jsret;
			do {
				if (ret) {
					js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCSkeleton>(cx, ret);
					jsret = OBJECT_TO_JSVAL(proxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	do {
		if (argc == 3) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			double arg2;
			ok &= JS_ValueToNumber(cx, argv[2], &arg2);
			if (!ok) { ok = JS_TRUE; break; }
			cocos2d::extension::CCSkeleton* ret = cocos2d::extension::CCSkeleton::createWithFile(arg0, arg1, arg2);
			jsval jsret;
			do {
				if (ret) {
					js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCSkeleton>(cx, ret);
					jsret = OBJECT_TO_JSVAL(proxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	
	do {
		if (argc == 2) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			Atlas* arg1;
			#pragma warning NO CONVERSION TO NATIVE FOR Atlas*;
			if (!ok) { ok = JS_TRUE; break; }
			cocos2d::extension::CCSkeleton* ret = cocos2d::extension::CCSkeleton::createWithFile(arg0, arg1);
			jsval jsret;
			do {
				if (ret) {
					js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCSkeleton>(cx, ret);
					jsret = OBJECT_TO_JSVAL(proxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	do {
		if (argc == 3) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			Atlas* arg1;
			#pragma warning NO CONVERSION TO NATIVE FOR Atlas*;
			if (!ok) { ok = JS_TRUE; break; }
			double arg2;
			ok &= JS_ValueToNumber(cx, argv[2], &arg2);
			if (!ok) { ok = JS_TRUE; break; }
			cocos2d::extension::CCSkeleton* ret = cocos2d::extension::CCSkeleton::createWithFile(arg0, arg1, arg2);
			jsval jsret;
			do {
				if (ret) {
					js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCSkeleton>(cx, ret);
					jsret = OBJECT_TO_JSVAL(proxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeleton_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	cocos2d::extension::CCSkeleton* cobj = NULL;
	do {
		if (argc == 2) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			Atlas* arg1;
			#pragma warning NO CONVERSION TO NATIVE FOR Atlas*;
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new cocos2d::extension::CCSkeleton(arg0, arg1);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<cocos2d::extension::CCSkeleton> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "cocos2d::extension::CCSkeleton");
		}
	} while(0);

	do {
		if (argc == 3) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			Atlas* arg1;
			#pragma warning NO CONVERSION TO NATIVE FOR Atlas*;
			if (!ok) { ok = JS_TRUE; break; }
			double arg2;
			ok &= JS_ValueToNumber(cx, argv[2], &arg2);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new cocos2d::extension::CCSkeleton(arg0, arg1, arg2);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<cocos2d::extension::CCSkeleton> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "cocos2d::extension::CCSkeleton");
		}
	} while(0);

	do {
		if (argc == 1) {
			SkeletonData* arg0;
			#pragma warning NO CONVERSION TO NATIVE FOR SkeletonData*;
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new cocos2d::extension::CCSkeleton(arg0);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<cocos2d::extension::CCSkeleton> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "cocos2d::extension::CCSkeleton");
		}
	} while(0);

	do {
		if (argc == 2) {
			SkeletonData* arg0;
			#pragma warning NO CONVERSION TO NATIVE FOR SkeletonData*;
			if (!ok) { ok = JS_TRUE; break; }
			JSBool arg1;
			ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new cocos2d::extension::CCSkeleton(arg0, arg1);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<cocos2d::extension::CCSkeleton> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "cocos2d::extension::CCSkeleton");
		}
	} while(0);

	do {
		if (argc == 2) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new cocos2d::extension::CCSkeleton(arg0, arg1);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<cocos2d::extension::CCSkeleton> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "cocos2d::extension::CCSkeleton");
		}
	} while(0);

	do {
		if (argc == 3) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			double arg2;
			ok &= JS_ValueToNumber(cx, argv[2], &arg2);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new cocos2d::extension::CCSkeleton(arg0, arg1, arg2);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<cocos2d::extension::CCSkeleton> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "cocos2d::extension::CCSkeleton");
		}
	} while(0);

	if (cobj) {
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}



extern JSObject *jsb_CCNodeRGBA_prototype;

void js_cocos2dx_spine_CCSkeleton_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (CCSkeleton)", obj);
}

static JSBool js_cocos2dx_spine_CCSkeleton_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    cocos2d::extension::CCSkeleton *nobj = new cocos2d::extension::CCSkeleton();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::CCSkeleton");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_cocos2dx_spine_CCSkeleton(JSContext *cx, JSObject *global) {
	jsb_CCSkeleton_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_CCSkeleton_class->name = "Skeleton";
	jsb_CCSkeleton_class->addProperty = JS_PropertyStub;
	jsb_CCSkeleton_class->delProperty = JS_PropertyStub;
	jsb_CCSkeleton_class->getProperty = JS_PropertyStub;
	jsb_CCSkeleton_class->setProperty = JS_StrictPropertyStub;
	jsb_CCSkeleton_class->enumerate = JS_EnumerateStub;
	jsb_CCSkeleton_class->resolve = JS_ResolveStub;
	jsb_CCSkeleton_class->convert = JS_ConvertStub;
	jsb_CCSkeleton_class->finalize = js_cocos2dx_spine_CCSkeleton_finalize;
	jsb_CCSkeleton_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("draw", js_cocos2dx_spine_CCSkeleton_draw, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSlotsToSetupPose", js_cocos2dx_spine_CCSkeleton_setSlotsToSetupPose, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setOpacityModifyRGB", js_cocos2dx_spine_CCSkeleton_setOpacityModifyRGB, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBlendFunc", js_cocos2dx_spine_CCSkeleton_setBlendFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setToSetupPose", js_cocos2dx_spine_CCSkeleton_setToSetupPose, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("update", js_cocos2dx_spine_CCSkeleton_update, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getAttachment", js_cocos2dx_spine_CCSkeleton_getAttachment, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setAttachment", js_cocos2dx_spine_CCSkeleton_setAttachment, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getBlendFunc", js_cocos2dx_spine_CCSkeleton_getBlendFunc, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSkin", js_cocos2dx_spine_CCSkeleton_setSkin, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("findSlot", js_cocos2dx_spine_CCSkeleton_findSlot, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("updateWorldTransform", js_cocos2dx_spine_CCSkeleton_updateWorldTransform, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("boundingBox", js_cocos2dx_spine_CCSkeleton_boundingBox, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBonesToSetupPose", js_cocos2dx_spine_CCSkeleton_setBonesToSetupPose, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("findBone", js_cocos2dx_spine_CCSkeleton_findBone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isOpacityModifyRGB", js_cocos2dx_spine_CCSkeleton_isOpacityModifyRGB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_cocos2dx_spine_CCSkeleton_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("createWithFile", js_cocos2dx_spine_CCSkeleton_createWithFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_CCSkeleton_prototype = JS_InitClass(
		cx, global,
		jsb_CCNodeRGBA_prototype,
		jsb_CCSkeleton_class,
		js_cocos2dx_spine_CCSkeleton_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "Skeleton", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::CCSkeleton> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_CCSkeleton_class;
		p->proto = jsb_CCSkeleton_prototype;
		p->parentProto = jsb_CCNodeRGBA_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *jsb_CCSkeletonAnimation_class;
JSObject *jsb_CCSkeletonAnimation_prototype;

JSBool js_cocos2dx_spine_CCSkeletonAnimation_addAnimationState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeletonAnimation* cobj = (cocos2d::extension::CCSkeletonAnimation *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->addAnimationState();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 1) {
		AnimationStateData* arg0;
		#pragma warning NO CONVERSION TO NATIVE FOR AnimationStateData*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->addAnimationState(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeletonAnimation_setAnimationStateData(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeletonAnimation* cobj = (cocos2d::extension::CCSkeletonAnimation *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		AnimationStateData* arg0;
		#pragma warning NO CONVERSION TO NATIVE FOR AnimationStateData*;
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setAnimationStateData(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		AnimationStateData* arg0;
		int arg1;
		#pragma warning NO CONVERSION TO NATIVE FOR AnimationStateData*;
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setAnimationStateData(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeletonAnimation_update(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeletonAnimation* cobj = (cocos2d::extension::CCSkeletonAnimation *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->update(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeletonAnimation_setMix(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeletonAnimation* cobj = (cocos2d::extension::CCSkeletonAnimation *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 3) {
		const char* arg0;
		const char* arg1;
		double arg2;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		ok &= JS_ValueToNumber(cx, argv[2], &arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setMix(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 4) {
		const char* arg0;
		const char* arg1;
		double arg2;
		int arg3;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		ok &= JS_ValueToNumber(cx, argv[2], &arg2);
		ok &= jsval_to_int32(cx, argv[3], (int32_t *)&arg3);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setMix(arg0, arg1, arg2, arg3);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeletonAnimation_setAnimation(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeletonAnimation* cobj = (cocos2d::extension::CCSkeletonAnimation *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		const char* arg0;
		JSBool arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setAnimation(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 3) {
		const char* arg0;
		JSBool arg1;
		int arg2;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		ok &= jsval_to_int32(cx, argv[2], (int32_t *)&arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->setAnimation(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeletonAnimation_clearAnimation(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeletonAnimation* cobj = (cocos2d::extension::CCSkeletonAnimation *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 0) {
		cobj->clearAnimation();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->clearAnimation(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeletonAnimation_addAnimation(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cocos2d::extension::CCSkeletonAnimation* cobj = (cocos2d::extension::CCSkeletonAnimation *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "Invalid Native Object");
	if (argc == 2) {
		const char* arg0;
		JSBool arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->addAnimation(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 3) {
		const char* arg0;
		JSBool arg1;
		double arg2;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		ok &= JS_ValueToNumber(cx, argv[2], &arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->addAnimation(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 4) {
		const char* arg0;
		JSBool arg1;
		double arg2;
		int arg3;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		ok &= JS_ValueToNumber(cx, argv[2], &arg2);
		ok &= jsval_to_int32(cx, argv[3], (int32_t *)&arg3);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
		cobj->addAnimation(arg0, arg1, arg2, arg3);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeletonAnimation_createWithFile(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	
	do {
		if (argc == 2) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			cocos2d::extension::CCSkeletonAnimation* ret = cocos2d::extension::CCSkeletonAnimation::createWithFile(arg0, arg1);
			jsval jsret;
			do {
				if (ret) {
					js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCSkeletonAnimation>(cx, ret);
					jsret = OBJECT_TO_JSVAL(proxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	do {
		if (argc == 3) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			double arg2;
			ok &= JS_ValueToNumber(cx, argv[2], &arg2);
			if (!ok) { ok = JS_TRUE; break; }
			cocos2d::extension::CCSkeletonAnimation* ret = cocos2d::extension::CCSkeletonAnimation::createWithFile(arg0, arg1, arg2);
			jsval jsret;
			do {
				if (ret) {
					js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCSkeletonAnimation>(cx, ret);
					jsret = OBJECT_TO_JSVAL(proxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	
	do {
		if (argc == 2) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			Atlas* arg1;
			#pragma warning NO CONVERSION TO NATIVE FOR Atlas*;
			if (!ok) { ok = JS_TRUE; break; }
			cocos2d::extension::CCSkeletonAnimation* ret = cocos2d::extension::CCSkeletonAnimation::createWithFile(arg0, arg1);
			jsval jsret;
			do {
				if (ret) {
					js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCSkeletonAnimation>(cx, ret);
					jsret = OBJECT_TO_JSVAL(proxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	do {
		if (argc == 3) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			Atlas* arg1;
			#pragma warning NO CONVERSION TO NATIVE FOR Atlas*;
			if (!ok) { ok = JS_TRUE; break; }
			double arg2;
			ok &= JS_ValueToNumber(cx, argv[2], &arg2);
			if (!ok) { ok = JS_TRUE; break; }
			cocos2d::extension::CCSkeletonAnimation* ret = cocos2d::extension::CCSkeletonAnimation::createWithFile(arg0, arg1, arg2);
			jsval jsret;
			do {
				if (ret) {
					js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCSkeletonAnimation>(cx, ret);
					jsret = OBJECT_TO_JSVAL(proxy->obj);
				} else {
					jsret = JSVAL_NULL;
				}
			} while (0);
			JS_SET_RVAL(cx, vp, jsret);
			return JS_TRUE;
		}
	} while (0);
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}
JSBool js_cocos2dx_spine_CCSkeletonAnimation_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	cocos2d::extension::CCSkeletonAnimation* cobj = NULL;
	do {
		if (argc == 2) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			Atlas* arg1;
			#pragma warning NO CONVERSION TO NATIVE FOR Atlas*;
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new cocos2d::extension::CCSkeletonAnimation(arg0, arg1);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<cocos2d::extension::CCSkeletonAnimation> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "cocos2d::extension::CCSkeletonAnimation");
		}
	} while(0);

	do {
		if (argc == 3) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			Atlas* arg1;
			#pragma warning NO CONVERSION TO NATIVE FOR Atlas*;
			if (!ok) { ok = JS_TRUE; break; }
			double arg2;
			ok &= JS_ValueToNumber(cx, argv[2], &arg2);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new cocos2d::extension::CCSkeletonAnimation(arg0, arg1, arg2);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<cocos2d::extension::CCSkeletonAnimation> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "cocos2d::extension::CCSkeletonAnimation");
		}
	} while(0);

	do {
		if (argc == 1) {
			SkeletonData* arg0;
			#pragma warning NO CONVERSION TO NATIVE FOR SkeletonData*;
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new cocos2d::extension::CCSkeletonAnimation(arg0);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<cocos2d::extension::CCSkeletonAnimation> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "cocos2d::extension::CCSkeletonAnimation");
		}
	} while(0);

	do {
		if (argc == 2) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new cocos2d::extension::CCSkeletonAnimation(arg0, arg1);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<cocos2d::extension::CCSkeletonAnimation> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "cocos2d::extension::CCSkeletonAnimation");
		}
	} while(0);

	do {
		if (argc == 3) {
			const char* arg0;
			std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			const char* arg1;
			std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
			if (!ok) { ok = JS_TRUE; break; }
			double arg2;
			ok &= JS_ValueToNumber(cx, argv[2], &arg2);
			if (!ok) { ok = JS_TRUE; break; }
			cobj = new cocos2d::extension::CCSkeletonAnimation(arg0, arg1, arg2);
			cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
			if (_ccobj) {
				_ccobj->autorelease();
			}
			TypeTest<cocos2d::extension::CCSkeletonAnimation> t;
			js_type_class_t *typeClass;
			uint32_t typeId = t.s_id();
			HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
			assert(typeClass);
			obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
			js_proxy_t* proxy = jsb_new_proxy(cobj, obj);
			JS_AddNamedObjectRoot(cx, &proxy->obj, "cocos2d::extension::CCSkeletonAnimation");
		}
	} while(0);

	if (cobj) {
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments");
	return JS_FALSE;
}



extern JSObject *jsb_CCSkeleton_prototype;

void js_cocos2dx_spine_CCSkeletonAnimation_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (CCSkeletonAnimation)", obj);
}

static JSBool js_cocos2dx_spine_CCSkeletonAnimation_ctor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
    cocos2d::extension::CCSkeletonAnimation *nobj = new cocos2d::extension::CCSkeletonAnimation();
    js_proxy_t* p = jsb_new_proxy(nobj, obj);
    nobj->autorelease();
    JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::CCSkeletonAnimation");
    JS_SET_RVAL(cx, vp, JSVAL_VOID);
    return JS_TRUE;
}

void js_register_cocos2dx_spine_CCSkeletonAnimation(JSContext *cx, JSObject *global) {
	jsb_CCSkeletonAnimation_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_CCSkeletonAnimation_class->name = "SkeletonAnimation";
	jsb_CCSkeletonAnimation_class->addProperty = JS_PropertyStub;
	jsb_CCSkeletonAnimation_class->delProperty = JS_PropertyStub;
	jsb_CCSkeletonAnimation_class->getProperty = JS_PropertyStub;
	jsb_CCSkeletonAnimation_class->setProperty = JS_StrictPropertyStub;
	jsb_CCSkeletonAnimation_class->enumerate = JS_EnumerateStub;
	jsb_CCSkeletonAnimation_class->resolve = JS_ResolveStub;
	jsb_CCSkeletonAnimation_class->convert = JS_ConvertStub;
	jsb_CCSkeletonAnimation_class->finalize = js_cocos2dx_spine_CCSkeletonAnimation_finalize;
	jsb_CCSkeletonAnimation_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("addAnimationState", js_cocos2dx_spine_CCSkeletonAnimation_addAnimationState, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setAnimationStateData", js_cocos2dx_spine_CCSkeletonAnimation_setAnimationStateData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("update", js_cocos2dx_spine_CCSkeletonAnimation_update, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMix", js_cocos2dx_spine_CCSkeletonAnimation_setMix, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setAnimation", js_cocos2dx_spine_CCSkeletonAnimation_setAnimation, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("clearAnimation", js_cocos2dx_spine_CCSkeletonAnimation_clearAnimation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("addAnimation", js_cocos2dx_spine_CCSkeletonAnimation_addAnimation, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ctor", js_cocos2dx_spine_CCSkeletonAnimation_ctor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("createWithFile", js_cocos2dx_spine_CCSkeletonAnimation_createWithFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_CCSkeletonAnimation_prototype = JS_InitClass(
		cx, global,
		jsb_CCSkeleton_prototype,
		jsb_CCSkeletonAnimation_class,
		js_cocos2dx_spine_CCSkeletonAnimation_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "SkeletonAnimation", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::CCSkeletonAnimation> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = jsb_CCSkeletonAnimation_class;
		p->proto = jsb_CCSkeletonAnimation_prototype;
		p->parentProto = jsb_CCSkeleton_prototype;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}

void register_all_cocos2dx_spine(JSContext* cx, JSObject* obj) {
	// first, try to get the ns
	jsval nsval;
	JSObject *ns;
	JS_GetProperty(cx, obj, "sp", &nsval);
	if (nsval == JSVAL_VOID) {
		ns = JS_NewObject(cx, NULL, NULL, NULL);
		nsval = OBJECT_TO_JSVAL(ns);
		JS_SetProperty(cx, obj, "sp", &nsval);
	} else {
		JS_ValueToObject(cx, nsval, &ns);
	}
	obj = ns;

	js_register_cocos2dx_spine_CCSkeleton(cx, obj);
	js_register_cocos2dx_spine_CCSkeletonAnimation(cx, obj);
}

