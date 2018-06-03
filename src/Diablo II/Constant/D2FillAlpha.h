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

#ifndef SGD2MAPI_DIABLOII_CONSTANT_D2FILLALPHA_H_
#define SGD2MAPI_DIABLOII_CONSTANT_D2FILLALPHA_H_

namespace slashgaming::diabloii::constant {

enum class D2FillAlphas {
    k0PercentOpaque = 0,
    k50PercentOpaque = 1,
    k75PercentOpaque = 2,
    k90PercentOpaque = 3,
    k100PercentOpaque = 4,
    k90PercentBlack = 5,
    k100PercentBlack = 6,
};

/**
 * Returns the resolved raw integer value of the constant, based on the running
 * game version and architecture.
 */
int ResolveD2FillAlphaToValue(enum D2FillAlphas fill_alpha);

/**
 * Returns the resolved constant that is associated with the specified integer,
 * based on the running game version and architecture.
 */
enum D2FillAlphas ResolveValueToD2FillAlpha(int raw_value);

} // namespace slashgaming::diabloii::constant

#endif // SGD2MAPI_DIABLOII_CONSTANT_D2FILLALPHA_H_
