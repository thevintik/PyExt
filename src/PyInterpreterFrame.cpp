#include "PyInterpreterFrame.h"
#include "PyFrameObject.h"
#include "PyDictObject.h"
#include "PyFunctionObject.h"
#include "PyCodeObject.h"

#include "fieldAsPyObject.h"

namespace PyExt::Remote {

	class _PyInterpreterFrame;

	_PyInterpreterFrame::_PyInterpreterFrame(const RemoteType& remoteType)
		: RemoteType(remoteType)
	{
	}


	auto _PyInterpreterFrame::previous() const -> std::unique_ptr<_PyInterpreterFrame>
	{
		return std::make_unique<_PyInterpreterFrame>(RemoteType(remoteType().Field("previous")));
	}

	auto _PyInterpreterFrame::f_func() const -> std::unique_ptr<PyFunctionObject>
	{
		return utils::fieldAsPyObject<PyFunctionObject>(remoteType(), "f_func");
	}
	auto _PyInterpreterFrame::f_globals() const -> std::unique_ptr<PyDictObject>
	{
		return utils::fieldAsPyObject<PyDictObject>(remoteType(), "f_globals");
	}
	auto _PyInterpreterFrame::f_builtins() const -> std::unique_ptr<PyDictObject>
	{
		return utils::fieldAsPyObject<PyDictObject>(remoteType(), "f_builtins");
	}
	auto _PyInterpreterFrame::f_locals() const -> std::unique_ptr<PyDictObject>
	{
		return utils::fieldAsPyObject<PyDictObject>(remoteType(), "f_locals");
	}
	auto _PyInterpreterFrame::f_code() const -> std::unique_ptr<PyCodeObject>
	{
		return utils::fieldAsPyObject<PyCodeObject>(remoteType(), "f_code");
	}
	

	_PyInterpreterFrame::~_PyInterpreterFrame()
	{
	}

}
