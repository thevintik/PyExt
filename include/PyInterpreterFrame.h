#pragma once

#include "RemoteType.h"

namespace PyExt::Remote {

	class PyDictObject;
	class PyCodeObject;
	class PyFunctionObject;

	// This was introduced in 3.11
	// https://github.com/python/cpython/blob/3.10/Include/cpython/frameobject.h#L28
	// https://github.com/python/cpython/blob/3.11/Include/internal/pycore_frame.h#L47
	class PYEXT_PUBLIC _PyInterpreterFrame : private RemoteType
	{
	public:
		explicit _PyInterpreterFrame(const RemoteType& remoteType);
		~_PyInterpreterFrame();

	public:
		using RemoteType::offset;
		auto f_func() const->std::unique_ptr<PyFunctionObject>;
		auto f_globals() const->std::unique_ptr<PyDictObject>;
		auto f_builtins() const->std::unique_ptr<PyDictObject>;
		auto f_locals() const->std::unique_ptr<PyDictObject>;/* May be NULL */
		auto f_code() const->std::unique_ptr<PyCodeObject>;
		auto previous() const->std::unique_ptr<_PyInterpreterFrame>;
	};
}