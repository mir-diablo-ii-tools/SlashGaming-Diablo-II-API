/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018  SlashGaming Community
 *
 * This file is part of SlashGaming Diablo II Modding API.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SGD2MAPI_DIABLOII_CONSTANT_D2DIFFICULTY_H_
#define SGD2MAPI_DIABLOII_CONSTANT_D2DIFFICULTY_H_

#ifdef SGD2MAPI_DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#elif defined(SGD2MAPI_DLLIMPORT)
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT
#endif

namespace slashgaming::diabloii::constant {

/**
 * The Diablo II game difficulties.
 */
enum class D2Difficulties {
    kNormal = 0,
    kNightmare = 1,
    kHell = 2,
};

/**
 * A wrapper class to represent the D2Difficulties constant in a version and
 * architecture agnostic way.
 */
class DLLEXPORT ExD2Difficulty {
public:
    /**
     * Creates an instance of ExD2Difficulty, resolving the value of the
     * constant to an integer based on the running game version and
     * architecture.
     */
    explicit ExD2Difficulty(enum D2Difficulties difficulty);

    explicit ExD2Difficulty(const ExD2Difficulty& base_constant) = default;
    explicit ExD2Difficulty(ExD2Difficulty&& base_constant) = default;

    ExD2Difficulty& operator=(const ExD2Difficulty& rhs) = default;
    ExD2Difficulty& operator=(ExD2Difficulty&& rhs) = default;

    /**
     * Returns the resolved value that corresponds to this instance of the
     * constant.
     */
    int value() const;

    /**
     * Returns the value of the constant that corresponds to this instance of
     * the constant. The underlying value of returned does not necessarily
     * correspond to that used in the game. Use value() for that purpose.
     */
    enum D2Difficulties difficulty() const;

private:
    enum D2Difficulties difficulty_;
    int value_;

    static int ResolveValue(enum D2Difficulties difficulty);
};

} // namespace slashgaming::diabloii::constant

#undef DLLEXPORT
#endif // SGD2MAPI_DIABLOII_CONSTANT_D2DIFFICULTY_H_
