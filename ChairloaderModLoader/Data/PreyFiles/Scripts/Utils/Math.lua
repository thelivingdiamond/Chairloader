function ConstVec(A0_9903)
  local L1_9904
  return A0_9903
end
g_Vectors = {
  v000 = ConstVec({
    x = 0,
    y = 0,
    z = 0
  }),
  v001 = ConstVec({
    x = 0,
    y = 0,
    z = 1
  }),
  v010 = ConstVec({
    x = 0,
    y = 1,
    z = 0
  }),
  v011 = ConstVec({
    x = 0,
    y = 1,
    z = 1
  }),
  v100 = ConstVec({
    x = 1,
    y = 0,
    z = 0
  }),
  v101 = ConstVec({
    x = 1,
    y = 0,
    z = 1
  }),
  v110 = ConstVec({
    x = 1,
    y = 1,
    z = 0
  }),
  v111 = ConstVec({
    x = 1,
    y = 1,
    z = 1
  }),
  up = ConstVec({
    x = 0,
    y = 0,
    z = 1
  }),
  down = ConstVec({
    x = 0,
    y = 0,
    z = -1
  }),
  temp = {
    x = 0,
    y = 0,
    z = 0
  },
  tempColor = {
    x = 0,
    y = 0,
    z = 0
  },
  temp_v1 = {
    x = 0,
    y = 0,
    z = 0
  },
  temp_v2 = {
    x = 0,
    y = 0,
    z = 0
  },
  temp_v3 = {
    x = 0,
    y = 0,
    z = 0
  },
  temp_v4 = {
    x = 0,
    y = 0,
    z = 0
  },
  temp_v5 = {
    x = 0,
    y = 0,
    z = 0
  },
  temp_v6 = {
    x = 0,
    y = 0,
    z = 0
  },
  vecMathTemp1 = {
    x = 0,
    y = 0,
    z = 0
  },
  vecMathTemp2 = {
    x = 0,
    y = 0,
    z = 0
  }
}
g_Rad2Deg = 180 / math.pi
g_Deg2Rad = math.pi / 180
g_Pi = math.pi
g_2Pi = 2 * math.pi
g_Pi2 = 0.5 * math.pi
random = math.random
math.randomseed(os.time())
random()
function IsNullVector(A0_9905)
  local L1_9906
  L1_9906 = A0_9905.x
  L1_9906 = L1_9906 == 0 and L1_9906 == 0 and L1_9906 == 0
  return L1_9906
end
function IsNotNullVector(A0_9907)
  local L1_9908
  L1_9908 = A0_9907.x
  L1_9908 = L1_9908 ~= 0 or L1_9908 ~= 0 or L1_9908 ~= 0
  return L1_9908
end
function LengthSqVector(A0_9909)
  local L1_9910, L2_9911, L3_9912
  L1_9910 = A0_9909.x
  L2_9911 = A0_9909.x
  L1_9910 = L1_9910 * L2_9911
  L2_9911 = A0_9909.y
  L3_9912 = A0_9909.y
  L2_9911 = L2_9911 * L3_9912
  L1_9910 = L1_9910 + L2_9911
  L2_9911 = A0_9909.z
  L3_9912 = A0_9909.z
  L2_9911 = L2_9911 * L3_9912
  L1_9910 = L1_9910 + L2_9911
  return L1_9910
end
function LengthVector(A0_9913)
  return math.sqrt(LengthSqVector(A0_9913))
end
function DistanceSqVectors(A0_9914, A1_9915)
  local L2_9916, L3_9917, L4_9918, L5_9919, L6_9920
  L2_9916 = A0_9914.x
  L3_9917 = A1_9915.x
  L2_9916 = L2_9916 - L3_9917
  L3_9917 = A0_9914.y
  L4_9918 = A1_9915.y
  L3_9917 = L3_9917 - L4_9918
  L4_9918 = A0_9914.z
  L5_9919 = A1_9915.z
  L4_9918 = L4_9918 - L5_9919
  L5_9919 = L2_9916 * L2_9916
  L6_9920 = L3_9917 * L3_9917
  L5_9919 = L5_9919 + L6_9920
  L6_9920 = L4_9918 * L4_9918
  L5_9919 = L5_9919 + L6_9920
  return L5_9919
end
function DistanceSqVectors2d(A0_9921, A1_9922)
  local L2_9923, L3_9924, L4_9925, L5_9926
  L2_9923 = A0_9921.x
  L3_9924 = A1_9922.x
  L2_9923 = L2_9923 - L3_9924
  L3_9924 = A0_9921.y
  L4_9925 = A1_9922.y
  L3_9924 = L3_9924 - L4_9925
  L4_9925 = L2_9923 * L2_9923
  L5_9926 = L3_9924 * L3_9924
  L4_9925 = L4_9925 + L5_9926
  return L4_9925
end
function DistanceVectors(A0_9927, A1_9928)
  local L2_9929, L3_9930, L4_9931
  L2_9929 = A0_9927.x
  L3_9930 = A1_9928.x
  L2_9929 = L2_9929 - L3_9930
  L3_9930 = A0_9927.y
  L4_9931 = A1_9928.y
  L3_9930 = L3_9930 - L4_9931
  L4_9931 = A0_9927.z
  L4_9931 = L4_9931 - A1_9928.z
  return math.sqrt(L2_9929 * L2_9929 + L3_9930 * L3_9930 + L4_9931 * L4_9931)
end
function dotproduct3d(A0_9932, A1_9933)
  local L2_9934, L3_9935, L4_9936
  L2_9934 = A0_9932.x
  L3_9935 = A1_9933.x
  L2_9934 = L2_9934 * L3_9935
  L3_9935 = A0_9932.y
  L4_9936 = A1_9933.y
  L3_9935 = L3_9935 * L4_9936
  L2_9934 = L2_9934 + L3_9935
  L3_9935 = A0_9932.z
  L4_9936 = A1_9933.z
  L3_9935 = L3_9935 * L4_9936
  L2_9934 = L2_9934 + L3_9935
  return L2_9934
end
function dotproduct2d(A0_9937, A1_9938)
  local L2_9939, L3_9940
  L2_9939 = A0_9937.x
  L3_9940 = A1_9938.x
  L2_9939 = L2_9939 * L3_9940
  L3_9940 = A0_9937.y
  L3_9940 = L3_9940 * A1_9938.y
  L2_9939 = L2_9939 + L3_9940
  return L2_9939
end
function LogVec(A0_9941, A1_9942)
  Log("%s = (%f %f %f)", A0_9941, A1_9942.x, A1_9942.y, A1_9942.z)
end
function ZeroVector(A0_9943)
  local L1_9944
  A0_9943.x = 0
  A0_9943.y = 0
  A0_9943.z = 0
end
function CopyVector(A0_9945, A1_9946)
  local L2_9947
  L2_9947 = A1_9946.x
  A0_9945.x = L2_9947
  L2_9947 = A1_9946.y
  A0_9945.y = L2_9947
  L2_9947 = A1_9946.z
  A0_9945.z = L2_9947
end
function SumVectors(A0_9948, A1_9949)
  local L2_9950, L3_9951, L4_9952
  L2_9950 = {}
  L3_9951 = A0_9948.x
  L4_9952 = A1_9949.x
  L3_9951 = L3_9951 + L4_9952
  L2_9950.x = L3_9951
  L3_9951 = A0_9948.y
  L4_9952 = A1_9949.y
  L3_9951 = L3_9951 + L4_9952
  L2_9950.y = L3_9951
  L3_9951 = A0_9948.z
  L4_9952 = A1_9949.z
  L3_9951 = L3_9951 + L4_9952
  L2_9950.z = L3_9951
  return L2_9950
end
function NegVector(A0_9953)
  local L1_9954
  L1_9954 = A0_9953.x
  L1_9954 = -L1_9954
  A0_9953.x = L1_9954
  L1_9954 = A0_9953.y
  L1_9954 = -L1_9954
  A0_9953.y = L1_9954
  L1_9954 = A0_9953.z
  L1_9954 = -L1_9954
  A0_9953.z = L1_9954
end
function SubVectors(A0_9955, A1_9956, A2_9957)
  local L3_9958, L4_9959
  L3_9958 = A1_9956.x
  L4_9959 = A2_9957.x
  L3_9958 = L3_9958 - L4_9959
  A0_9955.x = L3_9958
  L3_9958 = A1_9956.y
  L4_9959 = A2_9957.y
  L3_9958 = L3_9958 - L4_9959
  A0_9955.y = L3_9958
  L3_9958 = A1_9956.z
  L4_9959 = A2_9957.z
  L3_9958 = L3_9958 - L4_9959
  A0_9955.z = L3_9958
end
function FastSumVectors(A0_9960, A1_9961, A2_9962)
  local L3_9963, L4_9964
  L3_9963 = A1_9961.x
  L4_9964 = A2_9962.x
  L3_9963 = L3_9963 + L4_9964
  A0_9960.x = L3_9963
  L3_9963 = A1_9961.y
  L4_9964 = A2_9962.y
  L3_9963 = L3_9963 + L4_9964
  A0_9960.y = L3_9963
  L3_9963 = A1_9961.z
  L4_9964 = A2_9962.z
  L3_9963 = L3_9963 + L4_9964
  A0_9960.z = L3_9963
end
function DifferenceVectors(A0_9965, A1_9966)
  local L2_9967, L3_9968, L4_9969
  L2_9967 = {}
  L3_9968 = A0_9965.x
  L4_9969 = A1_9966.x
  L3_9968 = L3_9968 - L4_9969
  L2_9967.x = L3_9968
  L3_9968 = A0_9965.y
  L4_9969 = A1_9966.y
  L3_9968 = L3_9968 - L4_9969
  L2_9967.y = L3_9968
  L3_9968 = A0_9965.z
  L4_9969 = A1_9966.z
  L3_9968 = L3_9968 - L4_9969
  L2_9967.z = L3_9968
  return L2_9967
end
function FastDifferenceVectors(A0_9970, A1_9971, A2_9972)
  local L3_9973, L4_9974
  L3_9973 = A1_9971.x
  L4_9974 = A2_9972.x
  L3_9973 = L3_9973 - L4_9974
  A0_9970.x = L3_9973
  L3_9973 = A1_9971.y
  L4_9974 = A2_9972.y
  L3_9973 = L3_9973 - L4_9974
  A0_9970.y = L3_9973
  L3_9973 = A1_9971.z
  L4_9974 = A2_9972.z
  L3_9973 = L3_9973 - L4_9974
  A0_9970.z = L3_9973
end
function ProductVectors(A0_9975, A1_9976)
  local L2_9977, L3_9978, L4_9979
  L2_9977 = {}
  L3_9978 = A0_9975.x
  L4_9979 = A1_9976.x
  L3_9978 = L3_9978 * L4_9979
  L2_9977.x = L3_9978
  L3_9978 = A0_9975.y
  L4_9979 = A1_9976.y
  L3_9978 = L3_9978 * L4_9979
  L2_9977.y = L3_9978
  L3_9978 = A0_9975.z
  L4_9979 = A1_9976.z
  L3_9978 = L3_9978 * L4_9979
  L2_9977.z = L3_9978
  return L2_9977
end
function FastProductVectors(A0_9980, A1_9981, A2_9982)
  local L3_9983, L4_9984
  L3_9983 = A1_9981.x
  L4_9984 = A2_9982.x
  L3_9983 = L3_9983 * L4_9984
  A0_9980.x = L3_9983
  L3_9983 = A1_9981.y
  L4_9984 = A2_9982.y
  L3_9983 = L3_9983 * L4_9984
  A0_9980.y = L3_9983
  L3_9983 = A1_9981.z
  L4_9984 = A2_9982.z
  L3_9983 = L3_9983 * L4_9984
  A0_9980.z = L3_9983
end
function ScaleVector(A0_9985, A1_9986)
  local L2_9987, L3_9988
  L2_9987 = {}
  L3_9988 = A0_9985.x
  L3_9988 = L3_9988 * A1_9986
  L2_9987.x = L3_9988
  L3_9988 = A0_9985.y
  L3_9988 = L3_9988 * A1_9986
  L2_9987.y = L3_9988
  L3_9988 = A0_9985.z
  L3_9988 = L3_9988 * A1_9986
  L2_9987.z = L3_9988
  return L2_9987
end
function ScaleVectorInPlace(A0_9989, A1_9990)
  local L2_9991
  L2_9991 = A0_9989.x
  L2_9991 = L2_9991 * A1_9990
  A0_9989.x = L2_9991
  L2_9991 = A0_9989.y
  L2_9991 = L2_9991 * A1_9990
  A0_9989.y = L2_9991
  L2_9991 = A0_9989.z
  L2_9991 = L2_9991 * A1_9990
  A0_9989.z = L2_9991
end
function NormalizeVector(A0_9992)
  local L1_9993
  L1_9993 = math
  L1_9993 = L1_9993.sqrt
  L1_9993 = L1_9993(LengthSqVector(A0_9992))
  if L1_9993 > 0 then
  else
  end
  A0_9992.x = A0_9992.x * 1.0E-4
  A0_9992.y = A0_9992.y * 1.0E-4
  A0_9992.z = A0_9992.z * 1.0E-4
  return A0_9992
end
function FastScaleVector(A0_9994, A1_9995, A2_9996)
  local L3_9997
  L3_9997 = A1_9995.x
  L3_9997 = L3_9997 * A2_9996
  A0_9994.x = L3_9997
  L3_9997 = A1_9995.y
  L3_9997 = L3_9997 * A2_9996
  A0_9994.y = L3_9997
  L3_9997 = A1_9995.z
  L3_9997 = L3_9997 * A2_9996
  A0_9994.z = L3_9997
end
function LerpColors(A0_9998, A1_9999, A2_10000)
  local L3_10001, L4_10002, L5_10003, L6_10004
  L3_10001 = g_Vectors
  L3_10001 = L3_10001.tempColor
  L4_10002 = A0_9998.x
  L5_10003 = A1_9999.x
  L6_10004 = A0_9998.x
  L5_10003 = L5_10003 - L6_10004
  L5_10003 = L5_10003 * A2_10000
  L4_10002 = L4_10002 + L5_10003
  L3_10001.x = L4_10002
  L3_10001 = g_Vectors
  L3_10001 = L3_10001.tempColor
  L4_10002 = A0_9998.y
  L5_10003 = A1_9999.y
  L6_10004 = A0_9998.y
  L5_10003 = L5_10003 - L6_10004
  L5_10003 = L5_10003 * A2_10000
  L4_10002 = L4_10002 + L5_10003
  L3_10001.y = L4_10002
  L3_10001 = g_Vectors
  L3_10001 = L3_10001.tempColor
  L4_10002 = A0_9998.z
  L5_10003 = A1_9999.z
  L6_10004 = A0_9998.z
  L5_10003 = L5_10003 - L6_10004
  L5_10003 = L5_10003 * A2_10000
  L4_10002 = L4_10002 + L5_10003
  L3_10001.z = L4_10002
  L3_10001 = g_Vectors
  L3_10001 = L3_10001.tempColor
  return L3_10001
end
function Lerp(A0_10005, A1_10006, A2_10007)
  local L3_10008
  L3_10008 = A1_10006 - A0_10005
  L3_10008 = L3_10008 * A2_10007
  L3_10008 = A0_10005 + L3_10008
  return L3_10008
end
function __max(A0_10009, A1_10010)
  if A1_10010 < A0_10009 then
    return A0_10009
  else
    return A1_10010
  end
end
function __min(A0_10011, A1_10012)
  if A0_10011 < A1_10012 then
    return A0_10011
  else
    return A1_10012
  end
end
function clamp(A0_10013, A1_10014, A2_10015)
  if A2_10015 < A0_10013 then
    A0_10013 = A2_10015
  end
  if A1_10014 > A0_10013 then
    A0_10013 = A1_10014
  end
  return A0_10013
end
function Interpolate(A0_10016, A1_10017, A2_10018)
  local L3_10019
  L3_10019 = A1_10017 - A0_10016
  if math.abs(L3_10019) < 0.001 then
    return A1_10017
  end
  return A0_10016 + L3_10019 * __min(A2_10018, 1)
end
function sgn(A0_10020)
  local L1_10021
  if A0_10020 == 0 then
    L1_10021 = 0
    return L1_10021
  elseif A0_10020 > 0 then
    L1_10021 = 1
    return L1_10021
  else
    L1_10021 = -1
    return L1_10021
  end
end
function sgnnz(A0_10022)
  return A0_10022 >= 0 and 1 or -1
end
function sqr(A0_10023)
  return A0_10023 * A0_10023
end
function randomF(A0_10024, A1_10025)
  local L2_10026
  if A1_10025 < A0_10024 then
    L2_10026 = A1_10025
    A1_10025 = A0_10024
    A0_10024 = L2_10026
  end
  L2_10026 = A1_10025 - A0_10024
  return A0_10024 + math.random() * L2_10026
end
function VecRotate90_Z(A0_10027)
  local L2_10028
  L2_10028 = A0_10027.x
  A0_10027.x = A0_10027.y
  A0_10027.y = -L2_10028
end
function VecRotateMinus90_Z(A0_10029)
  local L2_10030
  L2_10030 = A0_10029.x
  A0_10029.x = -A0_10029.y
  A0_10029.y = L2_10030
end
function iff(A0_10031, A1_10032, A2_10033)
  if A0_10031 then
    return A1_10032
  else
    return A2_10033
  end
end
function crossproduct3d(A0_10034, A1_10035, A2_10036)
  local L3_10037, L4_10038, L5_10039
  L3_10037 = A1_10035.y
  L4_10038 = A2_10036.z
  L3_10037 = L3_10037 * L4_10038
  L4_10038 = A1_10035.z
  L5_10039 = A2_10036.y
  L4_10038 = L4_10038 * L5_10039
  L3_10037 = L3_10037 - L4_10038
  A0_10034.x = L3_10037
  L3_10037 = A1_10035.z
  L4_10038 = A2_10036.x
  L3_10037 = L3_10037 * L4_10038
  L4_10038 = A1_10035.x
  L5_10039 = A2_10036.z
  L4_10038 = L4_10038 * L5_10039
  L3_10037 = L3_10037 - L4_10038
  A0_10034.y = L3_10037
  L3_10037 = A1_10035.x
  L4_10038 = A2_10036.y
  L3_10037 = L3_10037 * L4_10038
  L4_10038 = A1_10035.y
  L5_10039 = A2_10036.x
  L4_10038 = L4_10038 * L5_10039
  L3_10037 = L3_10037 - L4_10038
  A0_10034.z = L3_10037
end
function RotateVectorAroundR(A0_10040, A1_10041, A2_10042, A3_10043)
  local L4_10044, L5_10045, L6_10046, L7_10047, L8_10048, L9_10049
  L4_10044 = math
  L4_10044 = L4_10044.cos
  L5_10045 = A3_10043
  L4_10044 = L4_10044(L5_10045)
  L5_10045 = math
  L5_10045 = L5_10045.sin
  L6_10046 = A3_10043
  L5_10045 = L5_10045(L6_10046)
  L6_10046 = {}
  L7_10047 = {}
  L8_10048 = {}
  L9_10049 = {}
  CopyVector(L6_10046, A1_10041)
  FastScaleVector(L6_10046, L6_10046, L4_10044)
  CopyVector(L9_10049, A1_10041)
  FastScaleVector(L9_10049, L9_10049, L5_10045)
  crossproduct3d(L7_10047, A2_10042, L9_10049)
  CopyVector(L8_10048, A2_10042)
  FastScaleVector(L8_10048, L8_10048, dotproduct3d(A2_10042, A1_10041))
  FastScaleVector(L8_10048, L8_10048, 1 - L4_10044)
  CopyVector(A0_10040, L6_10046)
  FastSumVectors(A0_10040, L6_10046, L7_10047)
  FastSumVectors(A0_10040, A0_10040, L8_10048)
end
function ProjectVector(A0_10050, A1_10051, A2_10052)
  local L3_10053, L4_10054
  L3_10053 = {}
  L4_10054 = FastScaleVector
  L4_10054(L3_10053, A1_10051, -1)
  L4_10054 = dotproduct3d
  L4_10054 = L4_10054(L3_10053, A2_10052)
  CopyVector(A0_10050, A2_10052)
  FastScaleVector(A0_10050, A0_10050, L4_10054)
  FastSumVectors(A0_10050, A0_10050, A1_10051)
end
function DistanceLineAndPoint(A0_10055, A1_10056, A2_10057)
  local L3_10058, L4_10059, L5_10060, L6_10061
  L3_10058 = LengthVector
  L4_10059 = A1_10056
  L3_10058 = L3_10058(L4_10059)
  L4_10059 = nil
  L5_10060 = {}
  L6_10061 = {}
  SubVectors(L6_10061, A0_10055, A2_10057)
  crossproduct3d(L5_10060, A1_10056, L6_10061)
  L4_10059 = LengthVector(L5_10060)
  if L3_10058 > 0.01 then
  else
  end
  return 0
end
function GetDirection(A0_10062, A1_10063)
  local L2_10064
  L2_10064 = {}
  SubVectors(L2_10064, A1_10063, A0_10062)
  NormalizeVector(L2_10064)
  return L2_10064
end
function GetAngleBetweenVectors2D(A0_10065, A1_10066)
  return math.acos(dotproduct2d(A0_10065, A1_10066))
end
function GetAngleBetweenVectors(A0_10067, A1_10068)
  return math.acos(clamp(dotproduct3d(A0_10067, A1_10068), -1, 1))
end
