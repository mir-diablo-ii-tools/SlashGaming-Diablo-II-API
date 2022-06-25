# Mir Drualga Common For C
# Copyright (C) 2020-2022  Mir Drualga
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Additional permissions under GNU Affero General Public License version 3
# section 7
#
# If you modify this Program, or any covered work, by linking or combining
# it with any program (or a modified version of that program and its
# libraries), containing parts covered by the terms of an incompatible
# license, the licensors of this Program grant you additional permission
# to convey the resulting work.

# Mir Drualga Common For C++98
# Copyright (C) 2021-2022  Mir Drualga
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Additional permissions under GNU Affero General Public License version 3
# section 7
#
# If you modify this Program, or any covered work, by linking or combining
# it with any program (or a modified version of that program and its
# libraries), containing parts covered by the terms of an incompatible
# license, the licensors of this Program grant you additional permission
# to convey the resulting work.

cmake_minimum_required(VERSION 3.11)

include(FetchContent)

FetchContent_Declare(MDC
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/MirD-Common-C"
)

FetchContent_MakeAvailable(MDC)
