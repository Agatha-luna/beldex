#pragma once

#include <cstdint>

namespace cryptonote {

enum class txversion : uint16_t {
    v0 = 0,
    v1,
    v2_ringct,
    v3_per_output_unlock_times,
    v4_tx_types,
    _count,
  };
  enum class txtype : uint16_t {
    standard,
    state_change,
    key_image_unlock,
    stake,
    beldex_name_system,
    coin_burn,                // = 5 (HF18)
    deploy_new_asset,         // = 6 (HF22) — immediately after coin_burn (=5)
    emit_asset,               // = 7 (HF22)
    update_asset,             // = 8 (HF22)
    burn_asset,               // = 9 (HF22)
    register_gateway_address, // = 10 (HF23)
    update_gateway_address,   // = 11 (HF23)
    _count
    // NOTE: get_max_type_for_hf is a range check, so types enabled at an
    // earlier HF must have numerically smaller values. Confidential assets
    // ship first (HF22, values 6-9); the gateway-address types follow (HF23,
    // values 10-11) so update_gateway_address stays the maximum type
    // returned at HF23. See docs/GATEWAY_ADDRESS_PLAN.md §6.
  };

}
