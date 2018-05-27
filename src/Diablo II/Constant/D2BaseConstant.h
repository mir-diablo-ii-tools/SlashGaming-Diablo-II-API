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

#ifndef SGD2MAPI_DIABLOII_CONSTANT_D2BASECONSTANT_H_
#define SGD2MAPI_DIABLOII_CONSTANT_D2BASECONSTANT_H_

namespace slashgaming::diabloii::constant {

/**
 * The base class used to help declare version agnostic constants.
 */
class D2BaseConstant {
public:
    /**
     * Returns the raw value stored by this instance, after resolving the
     * values associated with the running game version.
     */
    explicit operator int();

    /**
     * Returns the raw value of this instance.
     */
    int get_value() const;

    /**
     * Returns whether this instance's raw value has been initialized.
     */
    bool is_initialized() const;

protected:
    D2BaseConstant() = default;

    explicit D2BaseConstant(const D2BaseConstant& base_constant) = default;
    explicit D2BaseConstant(D2BaseConstant&& base_constant) = default;

    D2BaseConstant& operator=(const D2BaseConstant& rhs) = default;
    D2BaseConstant& operator=(D2BaseConstant&& rhs) = default;

    /**
     * Resolves the value for both the constant used and the running game
     * version. Returns the resolved value.
     */
    virtual int ResolveValue() = 0;

private:
    int value_;
    bool is_initialized_;
};

} // namespace slashgaming::diabloii::constant

#endif // SGD2MAPI_DIABLOII_CONSTANT_D2BASECONSTANT_H_
