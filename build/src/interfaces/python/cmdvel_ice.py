# **********************************************************************
#
# Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
#
# This copy of Ice is licensed to you under the terms described in the
# ICE_LICENSE file included in this distribution.
#
# **********************************************************************
#
# Ice version 3.5.1
#
# <auto-generated>
#
# Generated from file `cmdvel.ice'
#
# Warning: do not edit this file.
#
# </auto-generated>
#

import Ice, IcePy

# Start of module jderobot
_M_jderobot = Ice.openModule('jderobot')
__name__ = 'jderobot'

if 'CMDVelData' not in _M_jderobot.__dict__:
    _M_jderobot.CMDVelData = Ice.createTempClass()
    class CMDVelData(Ice.Object):
        def __init__(self, linearX=0.0, linearY=0.0, linearZ=0.0, angularX=0.0, angularY=0.0, angularZ=0.0):
            self.linearX = linearX
            self.linearY = linearY
            self.linearZ = linearZ
            self.angularX = angularX
            self.angularY = angularY
            self.angularZ = angularZ

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::jderobot::CMDVelData')

        def ice_id(self, current=None):
            return '::jderobot::CMDVelData'

        def ice_staticId():
            return '::jderobot::CMDVelData'
        ice_staticId = staticmethod(ice_staticId)

        def __str__(self):
            return IcePy.stringify(self, _M_jderobot._t_CMDVelData)

        __repr__ = __str__

    _M_jderobot.CMDVelDataPrx = Ice.createTempClass()
    class CMDVelDataPrx(Ice.ObjectPrx):

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_jderobot.CMDVelDataPrx.ice_checkedCast(proxy, '::jderobot::CMDVelData', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_jderobot.CMDVelDataPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_jderobot._t_CMDVelDataPrx = IcePy.defineProxy('::jderobot::CMDVelData', CMDVelDataPrx)

    _M_jderobot._t_CMDVelData = IcePy.defineClass('::jderobot::CMDVelData', CMDVelData, -1, (), False, False, None, (), (
        ('linearX', (), IcePy._t_float, False, 0),
        ('linearY', (), IcePy._t_float, False, 0),
        ('linearZ', (), IcePy._t_float, False, 0),
        ('angularX', (), IcePy._t_float, False, 0),
        ('angularY', (), IcePy._t_float, False, 0),
        ('angularZ', (), IcePy._t_float, False, 0)
    ))
    CMDVelData._ice_type = _M_jderobot._t_CMDVelData

    _M_jderobot.CMDVelData = CMDVelData
    del CMDVelData

    _M_jderobot.CMDVelDataPrx = CMDVelDataPrx
    del CMDVelDataPrx

if 'CMDVel' not in _M_jderobot.__dict__:
    _M_jderobot.CMDVel = Ice.createTempClass()
    class CMDVel(Ice.Object):
        def __init__(self):
            if Ice.getType(self) == _M_jderobot.CMDVel:
                raise RuntimeError('jderobot.CMDVel is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::jderobot::CMDVel')

        def ice_id(self, current=None):
            return '::jderobot::CMDVel'

        def ice_staticId():
            return '::jderobot::CMDVel'
        ice_staticId = staticmethod(ice_staticId)

        def setCMDVelData(self, data, current=None):
            pass

        def __str__(self):
            return IcePy.stringify(self, _M_jderobot._t_CMDVel)

        __repr__ = __str__

    _M_jderobot.CMDVelPrx = Ice.createTempClass()
    class CMDVelPrx(Ice.ObjectPrx):

        def setCMDVelData(self, data, _ctx=None):
            return _M_jderobot.CMDVel._op_setCMDVelData.invoke(self, ((data, ), _ctx))

        def begin_setCMDVelData(self, data, _response=None, _ex=None, _sent=None, _ctx=None):
            return _M_jderobot.CMDVel._op_setCMDVelData.begin(self, ((data, ), _response, _ex, _sent, _ctx))

        def end_setCMDVelData(self, _r):
            return _M_jderobot.CMDVel._op_setCMDVelData.end(self, _r)

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_jderobot.CMDVelPrx.ice_checkedCast(proxy, '::jderobot::CMDVel', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_jderobot.CMDVelPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_jderobot._t_CMDVelPrx = IcePy.defineProxy('::jderobot::CMDVel', CMDVelPrx)

    _M_jderobot._t_CMDVel = IcePy.defineClass('::jderobot::CMDVel', CMDVel, -1, (), True, False, None, (), ())
    CMDVel._ice_type = _M_jderobot._t_CMDVel

    CMDVel._op_setCMDVelData = IcePy.Operation('setCMDVelData', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, None, (), (((), _M_jderobot._t_CMDVelData, False, 0),), (), ((), IcePy._t_int, False, 0), ())

    _M_jderobot.CMDVel = CMDVel
    del CMDVel

    _M_jderobot.CMDVelPrx = CMDVelPrx
    del CMDVelPrx

# End of module jderobot
