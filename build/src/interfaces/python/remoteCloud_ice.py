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
# Generated from file `remoteCloud.ice'
#
# Warning: do not edit this file.
#
# </auto-generated>
#

import Ice, IcePy

# Start of module jderobot
_M_jderobot = Ice.openModule('jderobot')
__name__ = 'jderobot'

if 'Time' not in _M_jderobot.__dict__:
    _M_jderobot.Time = Ice.createTempClass()
    class Time(object):
        def __init__(self, seconds=0, useconds=0):
            self.seconds = seconds
            self.useconds = useconds

        def __hash__(self):
            _h = 0
            _h = 5 * _h + Ice.getHash(self.seconds)
            _h = 5 * _h + Ice.getHash(self.useconds)
            return _h % 0x7fffffff

        def __compare(self, other):
            if other is None:
                return 1
            elif not isinstance(other, _M_jderobot.Time):
                return NotImplemented
            else:
                if self.seconds is None or other.seconds is None:
                    if self.seconds != other.seconds:
                        return (-1 if self.seconds is None else 1)
                else:
                    if self.seconds < other.seconds:
                        return -1
                    elif self.seconds > other.seconds:
                        return 1
                if self.useconds is None or other.useconds is None:
                    if self.useconds != other.useconds:
                        return (-1 if self.useconds is None else 1)
                else:
                    if self.useconds < other.useconds:
                        return -1
                    elif self.useconds > other.useconds:
                        return 1
                return 0

        def __lt__(self, other):
            r = self.__compare(other)
            if r is NotImplemented:
                return r
            else:
                return r < 0

        def __le__(self, other):
            r = self.__compare(other)
            if r is NotImplemented:
                return r
            else:
                return r <= 0

        def __gt__(self, other):
            r = self.__compare(other)
            if r is NotImplemented:
                return r
            else:
                return r > 0

        def __ge__(self, other):
            r = self.__compare(other)
            if r is NotImplemented:
                return r
            else:
                return r >= 0

        def __eq__(self, other):
            r = self.__compare(other)
            if r is NotImplemented:
                return r
            else:
                return r == 0

        def __ne__(self, other):
            r = self.__compare(other)
            if r is NotImplemented:
                return r
            else:
                return r != 0

        def __str__(self):
            return IcePy.stringify(self, _M_jderobot._t_Time)

        __repr__ = __str__

    _M_jderobot._t_Time = IcePy.defineStruct('::jderobot::Time', Time, (), (
        ('seconds', (), IcePy._t_long),
        ('useconds', (), IcePy._t_long)
    ))

    _M_jderobot.Time = Time
    del Time

# End of module jderobot

# Start of module jderobot
__name__ = 'jderobot'

if 'JderobotException' not in _M_jderobot.__dict__:
    _M_jderobot.JderobotException = Ice.createTempClass()
    class JderobotException(Ice.UserException):
        def __init__(self, what=''):
            self.what = what

        def __str__(self):
            return IcePy.stringifyException(self)

        __repr__ = __str__

        _ice_name = 'jderobot::JderobotException'

    _M_jderobot._t_JderobotException = IcePy.defineException('::jderobot::JderobotException', JderobotException, (), False, None, (('what', (), IcePy._t_string, False, 0),))
    JderobotException._ice_type = _M_jderobot._t_JderobotException

    _M_jderobot.JderobotException = JderobotException
    del JderobotException

if 'ConfigurationNotExistException' not in _M_jderobot.__dict__:
    _M_jderobot.ConfigurationNotExistException = Ice.createTempClass()
    class ConfigurationNotExistException(_M_jderobot.JderobotException):
        def __init__(self, what=''):
            _M_jderobot.JderobotException.__init__(self, what)

        def __str__(self):
            return IcePy.stringifyException(self)

        __repr__ = __str__

        _ice_name = 'jderobot::ConfigurationNotExistException'

    _M_jderobot._t_ConfigurationNotExistException = IcePy.defineException('::jderobot::ConfigurationNotExistException', ConfigurationNotExistException, (), False, _M_jderobot._t_JderobotException, ())
    ConfigurationNotExistException._ice_type = _M_jderobot._t_ConfigurationNotExistException

    _M_jderobot.ConfigurationNotExistException = ConfigurationNotExistException
    del ConfigurationNotExistException

if 'DataNotExistException' not in _M_jderobot.__dict__:
    _M_jderobot.DataNotExistException = Ice.createTempClass()
    class DataNotExistException(_M_jderobot.JderobotException):
        def __init__(self, what=''):
            _M_jderobot.JderobotException.__init__(self, what)

        def __str__(self):
            return IcePy.stringifyException(self)

        __repr__ = __str__

        _ice_name = 'jderobot::DataNotExistException'

    _M_jderobot._t_DataNotExistException = IcePy.defineException('::jderobot::DataNotExistException', DataNotExistException, (), False, _M_jderobot._t_JderobotException, ())
    DataNotExistException._ice_type = _M_jderobot._t_DataNotExistException

    _M_jderobot.DataNotExistException = DataNotExistException
    del DataNotExistException

if 'HardwareFailedException' not in _M_jderobot.__dict__:
    _M_jderobot.HardwareFailedException = Ice.createTempClass()
    class HardwareFailedException(_M_jderobot.JderobotException):
        def __init__(self, what=''):
            _M_jderobot.JderobotException.__init__(self, what)

        def __str__(self):
            return IcePy.stringifyException(self)

        __repr__ = __str__

        _ice_name = 'jderobot::HardwareFailedException'

    _M_jderobot._t_HardwareFailedException = IcePy.defineException('::jderobot::HardwareFailedException', HardwareFailedException, (), False, _M_jderobot._t_JderobotException, ())
    HardwareFailedException._ice_type = _M_jderobot._t_HardwareFailedException

    _M_jderobot.HardwareFailedException = HardwareFailedException
    del HardwareFailedException

if 'NoTopicException' not in _M_jderobot.__dict__:
    _M_jderobot.NoTopicException = Ice.createTempClass()
    class NoTopicException(_M_jderobot.JderobotException):
        def __init__(self, what=''):
            _M_jderobot.JderobotException.__init__(self, what)

        def __str__(self):
            return IcePy.stringifyException(self)

        __repr__ = __str__

        _ice_name = 'jderobot::NoTopicException'

    _M_jderobot._t_NoTopicException = IcePy.defineException('::jderobot::NoTopicException', NoTopicException, (), False, _M_jderobot._t_JderobotException, ())
    NoTopicException._ice_type = _M_jderobot._t_NoTopicException

    _M_jderobot.NoTopicException = NoTopicException
    del NoTopicException

if 'SubscriptionFailedException' not in _M_jderobot.__dict__:
    _M_jderobot.SubscriptionFailedException = Ice.createTempClass()
    class SubscriptionFailedException(_M_jderobot.JderobotException):
        def __init__(self, what=''):
            _M_jderobot.JderobotException.__init__(self, what)

        def __str__(self):
            return IcePy.stringifyException(self)

        __repr__ = __str__

        _ice_name = 'jderobot::SubscriptionFailedException'

    _M_jderobot._t_SubscriptionFailedException = IcePy.defineException('::jderobot::SubscriptionFailedException', SubscriptionFailedException, (), False, _M_jderobot._t_JderobotException, ())
    SubscriptionFailedException._ice_type = _M_jderobot._t_SubscriptionFailedException

    _M_jderobot.SubscriptionFailedException = SubscriptionFailedException
    del SubscriptionFailedException

if 'SubscriptionPushFailedException' not in _M_jderobot.__dict__:
    _M_jderobot.SubscriptionPushFailedException = Ice.createTempClass()
    class SubscriptionPushFailedException(_M_jderobot.JderobotException):
        def __init__(self, what=''):
            _M_jderobot.JderobotException.__init__(self, what)

        def __str__(self):
            return IcePy.stringifyException(self)

        __repr__ = __str__

        _ice_name = 'jderobot::SubscriptionPushFailedException'

    _M_jderobot._t_SubscriptionPushFailedException = IcePy.defineException('::jderobot::SubscriptionPushFailedException', SubscriptionPushFailedException, (), False, _M_jderobot._t_JderobotException, ())
    SubscriptionPushFailedException._ice_type = _M_jderobot._t_SubscriptionPushFailedException

    _M_jderobot.SubscriptionPushFailedException = SubscriptionPushFailedException
    del SubscriptionPushFailedException

# End of module jderobot

# Start of module jderobot
__name__ = 'jderobot'

if '_t_ByteSeq' not in _M_jderobot.__dict__:
    _M_jderobot._t_ByteSeq = IcePy.defineSequence('::jderobot::ByteSeq', (), IcePy._t_byte)

if '_t_IntSeq' not in _M_jderobot.__dict__:
    _M_jderobot._t_IntSeq = IcePy.defineSequence('::jderobot::IntSeq', (), IcePy._t_int)

if '_t_seqFloat' not in _M_jderobot.__dict__:
    _M_jderobot._t_seqFloat = IcePy.defineSequence('::jderobot::seqFloat', (), IcePy._t_float)

# End of module jderobot

# Start of module jderobot
__name__ = 'jderobot'

# End of module jderobot

# Start of module jderobot
__name__ = 'jderobot'

if 'RGBPoint' not in _M_jderobot.__dict__:
    _M_jderobot.RGBPoint = Ice.createTempClass()
    class RGBPoint(object):
        '''PCL'''
        def __init__(self, x=0.0, y=0.0, z=0.0, r=0.0, g=0.0, b=0.0, id=0):
            self.x = x
            self.y = y
            self.z = z
            self.r = r
            self.g = g
            self.b = b
            self.id = id

        def __eq__(self, other):
            if other is None:
                return False
            elif not isinstance(other, _M_jderobot.RGBPoint):
                return NotImplemented
            else:
                if self.x != other.x:
                    return False
                if self.y != other.y:
                    return False
                if self.z != other.z:
                    return False
                if self.r != other.r:
                    return False
                if self.g != other.g:
                    return False
                if self.b != other.b:
                    return False
                if self.id != other.id:
                    return False
                return True

        def __ne__(self, other):
            return not self.__eq__(other)

        def __str__(self):
            return IcePy.stringify(self, _M_jderobot._t_RGBPoint)

        __repr__ = __str__

    _M_jderobot._t_RGBPoint = IcePy.defineStruct('::jderobot::RGBPoint', RGBPoint, (), (
        ('x', (), IcePy._t_float),
        ('y', (), IcePy._t_float),
        ('z', (), IcePy._t_float),
        ('r', (), IcePy._t_float),
        ('g', (), IcePy._t_float),
        ('b', (), IcePy._t_float),
        ('id', (), IcePy._t_int)
    ))

    _M_jderobot.RGBPoint = RGBPoint
    del RGBPoint

if 'Point' not in _M_jderobot.__dict__:
    _M_jderobot.Point = Ice.createTempClass()
    class Point(object):
        def __init__(self, x=0.0, y=0.0, z=0.0):
            self.x = x
            self.y = y
            self.z = z

        def __eq__(self, other):
            if other is None:
                return False
            elif not isinstance(other, _M_jderobot.Point):
                return NotImplemented
            else:
                if self.x != other.x:
                    return False
                if self.y != other.y:
                    return False
                if self.z != other.z:
                    return False
                return True

        def __ne__(self, other):
            return not self.__eq__(other)

        def __str__(self):
            return IcePy.stringify(self, _M_jderobot._t_Point)

        __repr__ = __str__

    _M_jderobot._t_Point = IcePy.defineStruct('::jderobot::Point', Point, (), (
        ('x', (), IcePy._t_float),
        ('y', (), IcePy._t_float),
        ('z', (), IcePy._t_float)
    ))

    _M_jderobot.Point = Point
    del Point

if 'Segment' not in _M_jderobot.__dict__:
    _M_jderobot.Segment = Ice.createTempClass()
    class Segment(object):
        def __init__(self, fromPoint=Ice._struct_marker, toPoint=Ice._struct_marker):
            if fromPoint is Ice._struct_marker:
                self.fromPoint = _M_jderobot.Point()
            else:
                self.fromPoint = fromPoint
            if toPoint is Ice._struct_marker:
                self.toPoint = _M_jderobot.Point()
            else:
                self.toPoint = toPoint

        def __eq__(self, other):
            if other is None:
                return False
            elif not isinstance(other, _M_jderobot.Segment):
                return NotImplemented
            else:
                if self.fromPoint != other.fromPoint:
                    return False
                if self.toPoint != other.toPoint:
                    return False
                return True

        def __ne__(self, other):
            return not self.__eq__(other)

        def __str__(self):
            return IcePy.stringify(self, _M_jderobot._t_Segment)

        __repr__ = __str__

    _M_jderobot._t_Segment = IcePy.defineStruct('::jderobot::Segment', Segment, (), (
        ('fromPoint', (), _M_jderobot._t_Point),
        ('toPoint', (), _M_jderobot._t_Point)
    ))

    _M_jderobot.Segment = Segment
    del Segment

# End of module jderobot

# Start of module jderobot
__name__ = 'jderobot'

if '_t_RGBPointsPCL' not in _M_jderobot.__dict__:
    _M_jderobot._t_RGBPointsPCL = IcePy.defineSequence('::jderobot::RGBPointsPCL', (), _M_jderobot._t_RGBPoint)

if 'pointCloudData' not in _M_jderobot.__dict__:
    _M_jderobot.pointCloudData = Ice.createTempClass()
    class pointCloudData(Ice.Object):
        def __init__(self, p=None):
            self.p = p

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::jderobot::pointCloudData')

        def ice_id(self, current=None):
            return '::jderobot::pointCloudData'

        def ice_staticId():
            return '::jderobot::pointCloudData'
        ice_staticId = staticmethod(ice_staticId)

        def __str__(self):
            return IcePy.stringify(self, _M_jderobot._t_pointCloudData)

        __repr__ = __str__

    _M_jderobot.pointCloudDataPrx = Ice.createTempClass()
    class pointCloudDataPrx(Ice.ObjectPrx):

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_jderobot.pointCloudDataPrx.ice_checkedCast(proxy, '::jderobot::pointCloudData', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_jderobot.pointCloudDataPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_jderobot._t_pointCloudDataPrx = IcePy.defineProxy('::jderobot::pointCloudData', pointCloudDataPrx)

    _M_jderobot._t_pointCloudData = IcePy.defineClass('::jderobot::pointCloudData', pointCloudData, -1, (), False, False, None, (), (('p', (), _M_jderobot._t_RGBPointsPCL, False, 0),))
    pointCloudData._ice_type = _M_jderobot._t_pointCloudData

    _M_jderobot.pointCloudData = pointCloudData
    del pointCloudData

    _M_jderobot.pointCloudDataPrx = pointCloudDataPrx
    del pointCloudDataPrx

if 'pointCloud' not in _M_jderobot.__dict__:
    _M_jderobot.pointCloud = Ice.createTempClass()
    class pointCloud(Ice.Object):
        def __init__(self):
            if Ice.getType(self) == _M_jderobot.pointCloud:
                raise RuntimeError('jderobot.pointCloud is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::jderobot::pointCloud')

        def ice_id(self, current=None):
            return '::jderobot::pointCloud'

        def ice_staticId():
            return '::jderobot::pointCloud'
        ice_staticId = staticmethod(ice_staticId)

        def getCloudData(self, current=None):
            pass

        def __str__(self):
            return IcePy.stringify(self, _M_jderobot._t_pointCloud)

        __repr__ = __str__

    _M_jderobot.pointCloudPrx = Ice.createTempClass()
    class pointCloudPrx(Ice.ObjectPrx):

        def getCloudData(self, _ctx=None):
            return _M_jderobot.pointCloud._op_getCloudData.invoke(self, ((), _ctx))

        def begin_getCloudData(self, _response=None, _ex=None, _sent=None, _ctx=None):
            return _M_jderobot.pointCloud._op_getCloudData.begin(self, ((), _response, _ex, _sent, _ctx))

        def end_getCloudData(self, _r):
            return _M_jderobot.pointCloud._op_getCloudData.end(self, _r)

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_jderobot.pointCloudPrx.ice_checkedCast(proxy, '::jderobot::pointCloud', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_jderobot.pointCloudPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_jderobot._t_pointCloudPrx = IcePy.defineProxy('::jderobot::pointCloud', pointCloudPrx)

    _M_jderobot._t_pointCloud = IcePy.defineClass('::jderobot::pointCloud', pointCloud, -1, (), True, False, None, (), ())
    pointCloud._ice_type = _M_jderobot._t_pointCloud

    pointCloud._op_getCloudData = IcePy.Operation('getCloudData', Ice.OperationMode.Idempotent, Ice.OperationMode.Idempotent, False, None, (), (), (), ((), _M_jderobot._t_pointCloudData, False, 0), ())

    _M_jderobot.pointCloud = pointCloud
    del pointCloud

    _M_jderobot.pointCloudPrx = pointCloudPrx
    del pointCloudPrx

# End of module jderobot

# Start of module jderobot
__name__ = 'jderobot'

if 'remoteCloud' not in _M_jderobot.__dict__:
    _M_jderobot.remoteCloud = Ice.createTempClass()
    class remoteCloud(_M_jderobot.pointCloud):
        def __init__(self):
            if Ice.getType(self) == _M_jderobot.remoteCloud:
                raise RuntimeError('jderobot.remoteCloud is an abstract class')

        def ice_ids(self, current=None):
            return ('::Ice::Object', '::jderobot::pointCloud', '::jderobot::remoteCloud')

        def ice_id(self, current=None):
            return '::jderobot::remoteCloud'

        def ice_staticId():
            return '::jderobot::remoteCloud'
        ice_staticId = staticmethod(ice_staticId)

        def initConfiguration(self, current=None):
            pass

        def read(self, id, current=None):
            pass

        def write(self, data, id, current=None):
            pass

        def setConfiguration(self, id, current=None):
            pass

        def __str__(self):
            return IcePy.stringify(self, _M_jderobot._t_remoteCloud)

        __repr__ = __str__

    _M_jderobot.remoteCloudPrx = Ice.createTempClass()
    class remoteCloudPrx(_M_jderobot.pointCloudPrx):

        def initConfiguration(self, _ctx=None):
            return _M_jderobot.remoteCloud._op_initConfiguration.invoke(self, ((), _ctx))

        def begin_initConfiguration(self, _response=None, _ex=None, _sent=None, _ctx=None):
            return _M_jderobot.remoteCloud._op_initConfiguration.begin(self, ((), _response, _ex, _sent, _ctx))

        def end_initConfiguration(self, _r):
            return _M_jderobot.remoteCloud._op_initConfiguration.end(self, _r)

        def read(self, id, _ctx=None):
            return _M_jderobot.remoteCloud._op_read.invoke(self, ((id, ), _ctx))

        def begin_read(self, id, _response=None, _ex=None, _sent=None, _ctx=None):
            return _M_jderobot.remoteCloud._op_read.begin(self, ((id, ), _response, _ex, _sent, _ctx))

        def end_read(self, _r):
            return _M_jderobot.remoteCloud._op_read.end(self, _r)

        def write(self, data, id, _ctx=None):
            return _M_jderobot.remoteCloud._op_write.invoke(self, ((data, id), _ctx))

        def begin_write(self, data, id, _response=None, _ex=None, _sent=None, _ctx=None):
            return _M_jderobot.remoteCloud._op_write.begin(self, ((data, id), _response, _ex, _sent, _ctx))

        def end_write(self, _r):
            return _M_jderobot.remoteCloud._op_write.end(self, _r)

        def setConfiguration(self, id, _ctx=None):
            return _M_jderobot.remoteCloud._op_setConfiguration.invoke(self, ((id, ), _ctx))

        def begin_setConfiguration(self, id, _response=None, _ex=None, _sent=None, _ctx=None):
            return _M_jderobot.remoteCloud._op_setConfiguration.begin(self, ((id, ), _response, _ex, _sent, _ctx))

        def end_setConfiguration(self, _r):
            return _M_jderobot.remoteCloud._op_setConfiguration.end(self, _r)

        def checkedCast(proxy, facetOrCtx=None, _ctx=None):
            return _M_jderobot.remoteCloudPrx.ice_checkedCast(proxy, '::jderobot::remoteCloud', facetOrCtx, _ctx)
        checkedCast = staticmethod(checkedCast)

        def uncheckedCast(proxy, facet=None):
            return _M_jderobot.remoteCloudPrx.ice_uncheckedCast(proxy, facet)
        uncheckedCast = staticmethod(uncheckedCast)

    _M_jderobot._t_remoteCloudPrx = IcePy.defineProxy('::jderobot::remoteCloud', remoteCloudPrx)

    _M_jderobot._t_remoteCloud = IcePy.defineClass('::jderobot::remoteCloud', remoteCloud, -1, (), True, False, None, (_M_jderobot._t_pointCloud,), ())
    remoteCloud._ice_type = _M_jderobot._t_remoteCloud

    remoteCloud._op_initConfiguration = IcePy.Operation('initConfiguration', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, None, (), (), (), ((), IcePy._t_int, False, 0), ())
    remoteCloud._op_read = IcePy.Operation('read', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, None, (), (((), IcePy._t_int, False, 0),), (), ((), IcePy._t_string, False, 0), ())
    remoteCloud._op_write = IcePy.Operation('write', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, None, (), (((), IcePy._t_string, False, 0), ((), IcePy._t_int, False, 0)), (), ((), IcePy._t_int, False, 0), ())
    remoteCloud._op_setConfiguration = IcePy.Operation('setConfiguration', Ice.OperationMode.Normal, Ice.OperationMode.Normal, False, None, (), (((), IcePy._t_int, False, 0),), (), ((), IcePy._t_int, False, 0), ())

    _M_jderobot.remoteCloud = remoteCloud
    del remoteCloud

    _M_jderobot.remoteCloudPrx = remoteCloudPrx
    del remoteCloudPrx

# End of module jderobot
