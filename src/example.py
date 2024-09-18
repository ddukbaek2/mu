#--------------------------------------------------------------------------------
# 참조 모듈 목록.
#--------------------------------------------------------------------------------
from __future__ import annotations
from typing import Any, Final, Callable, Iterator, Optional, Type, TypeVar, Union, Tuple, List, Dict, Set, cast
import builtins
import sys
import os


#--------------------------------------------------------------------------------
# 바닐라 스타일에서는 사용전에 개별 패키지 임포트 필요.
# - 소스 디렉터리를 추가해야 소스 디렉터리 하위의 패키지를 자동 추가 할 수 있음.
#--------------------------------------------------------------------------------
exampleFilePath = os.path.abspath(__file__)
srcPath = os.path.dirname(exampleFilePath)
sys.path.append(srcPath)
import packageexample


#--------------------------------------------------------------------------------
# 출력.
#--------------------------------------------------------------------------------
def PrintExample():
	builtins.print("vanilla-python")
	packageexample.Print()