/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018-2019  Mir Drualga
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
 *
 *  Additional permissions under GNU Affero General Public License version 3
 *  section 7
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with Diablo II (or a modified version of that game and its
 *  libraries), containing parts covered by the terms of Blizzard End User
 *  License Agreement, the licensors of this Program grant you additional
 *  permission to convey the resulting work. This additional permission is
 *  also extended to any combination of expansions, mods, and remasters of
 *  the game.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#include "../../../include/cxx/game_patch/game_nop_patch.hpp"

#include <cstdlib>
#include <memory>
#include <utility>
#include <vector>

#include "../architecture_opcode.hpp"
#include "../../../include/cxx/game_address.hpp"
#include "../../../include/cxx/game_patch/game_patch_base.hpp"

namespace sgd2mapi {

GameNopPatch::GameNopPatch(
    const GameAddress& game_address,
    std::size_t patch_size
)
    : GamePatchBase(
          game_address,
          std::vector<std::uint8_t>(
              patch_size,
              static_cast<std::uint8_t>(OpCode::kNop)
          )
      ) {
}

GameNopPatch::GameNopPatch(
    GameAddress&& game_address,
    std::size_t patch_size
)
    : GamePatchBase(
          std::move(game_address),
          std::vector<std::uint8_t>(
              patch_size,
              static_cast<std::uint8_t>(OpCode::kNop)
          )
      ) {
}

GameNopPatch::GameNopPatch(
    const GameNopPatch&
) = default;

GameNopPatch::GameNopPatch(
    GameNopPatch&&
) noexcept = default;

GameNopPatch::~GameNopPatch(
    void
) = default;

GameNopPatch&
GameNopPatch::operator=(
    const GameNopPatch&
) = default;

GameNopPatch&
GameNopPatch::operator=(
    GameNopPatch&&
) noexcept = default;

GameNopPatch*
GameNopPatch::Clone(
    void
) const {
  return new GameNopPatch(*this);
}

GameNopPatch*
GameNopPatch::MoveToClone(
    void
) {
  return new GameNopPatch(
      std::move(this->game_address()),
      std::move(this->patch_size())
  );
}

} // namespace sgd2mapi

/**
 * C Interface
 */

struct SGD2MAPI_GameNopPatch*
SGD2MAPI_GameNopPatch_Create(
    const struct SGD2MAPI_GameAddress* c_game_address,
    std::size_t patch_size
) {
  struct SGD2MAPI_GameNopPatch* c_game_nop_patch =
      new SGD2MAPI_GameNopPatch;

  const sgd2mapi::GameAddress* actual_game_address =
      c_game_address->actual_ptr.get();

  c_game_nop_patch->actual_ptr =
      std::make_shared<sgd2mapi::GameNopPatch>(
          *actual_game_address,
          patch_size
      );

  return c_game_nop_patch;
}

struct SGD2MAPI_GamePatchBase*
SGD2MAPI_GameNopPatch_CreateAsGamePatchBase(
    const struct SGD2MAPI_GameAddress* c_game_address,
    std::size_t patch_size
) {
  struct SGD2MAPI_GameNopPatch* c_game_nop_patch =
      SGD2MAPI_GameNopPatch_Create(
          c_game_address,
          patch_size
      );

  return SGD2MAPI_GameNopPatch_UpcastToGamePatchBaseThenDestroy(
      c_game_nop_patch
  );
}

struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GameNopPatch_CreateAsGamePatchInterface(
    const struct SGD2MAPI_GameAddress* c_game_address,
    std::size_t patch_size
) {
  struct SGD2MAPI_GameNopPatch* c_game_nop_patch =
      SGD2MAPI_GameNopPatch_Create(
          c_game_address,
          patch_size
      );

  return SGD2MAPI_GameNopPatch_UpcastToGamePatchInterfaceThenDestroy(
      c_game_nop_patch
  );
}

void
SGD2MAPI_GameNopPatch_Destroy(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
) {
  delete c_game_nop_patch;
}

struct SGD2MAPI_GamePatchBase*
SGD2MAPI_GameNopPatch_UpcastToGamePatchBase(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
) {
  struct SGD2MAPI_GamePatchBase* c_game_patch_base =
      new SGD2MAPI_GamePatchBase;

  c_game_patch_base->actual_ptr = c_game_nop_patch->actual_ptr;

  return c_game_patch_base;
}

struct SGD2MAPI_GamePatchBase*
SGD2MAPI_GameNopPatch_UpcastToGamePatchBaseThenDestroy(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
) {
  struct SGD2MAPI_GamePatchBase* c_game_patch_base =
      SGD2MAPI_GameNopPatch_UpcastToGamePatchBase(
          c_game_nop_patch
      );

  SGD2MAPI_GameNopPatch_Destroy(c_game_nop_patch);

  return c_game_patch_base;
}

struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GameNopPatch_UpcastToGamePatchInterface(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
) {
  struct SGD2MAPI_GamePatchInterface* c_game_patch_interface =
      new SGD2MAPI_GamePatchInterface;

  c_game_patch_interface->actual_ptr = c_game_nop_patch->actual_ptr;

  return c_game_patch_interface;
}

struct SGD2MAPI_GamePatchInterface*
SGD2MAPI_GameNopPatch_UpcastToGamePatchInterfaceThenDestroy(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
) {
  struct SGD2MAPI_GamePatchInterface* c_game_patch_interface =
      SGD2MAPI_GameNopPatch_UpcastToGamePatchInterface(
          c_game_nop_patch
      );

  SGD2MAPI_GameNopPatch_Destroy(c_game_nop_patch);

  return c_game_patch_interface;
}

void
SGD2MAPI_GameNopPatch_Apply(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
) {
  c_game_nop_patch->actual_ptr->Apply();
}

void
SGD2MAPI_GameNopPatch_Remove(
    struct SGD2MAPI_GameNopPatch* c_game_nop_patch
) {
  c_game_nop_patch->actual_ptr->Remove();
}
