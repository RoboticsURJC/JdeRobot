
set(module "PyQt5")

usePython(2)
find_python_module(${module} REQUIRED)

string(TOUPPER ${module} module_upper)

if(PY_${module_upper})
	SET (QT5_PY_MODULES  PY_${module_upper})
	list(APPEND DEPS  python-pyqt5 python-pyqt5.qtsvg python-pyqt5.qsci)
	list(APPEND DEPS_DEV python-pyqt5 python-pyqt5.qtsvg python3-pyqt5 python3-pyqt5.qtsvg python-pyqt5.qsci)
endif(PY_${module_upper})
