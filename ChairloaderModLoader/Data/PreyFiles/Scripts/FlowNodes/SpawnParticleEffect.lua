local L0_9443, L1_9444
L0_9443 = {}
L0_9443.Category = "approved"
L1_9444 = {
  {"t_Activate", "bool"},
  {"Position", "vec3"},
  {"Direction", "vec3"},
  {"Effect", "string"}
}
L0_9443.Inputs = L1_9444
L1_9444 = {
  {"Done", "bool"}
}
L0_9443.Outputs = L1_9444
function L1_9444(A0_9445, A1_9446, A2_9447, A3_9448)
  if LengthSqVector(A2_9447) == 0 then
    A2_9447 = g_Vectors.v001
  end
  Particle.SpawnEffect(A3_9448, A1_9446, A2_9447, 1)
  return
end
L0_9443.Implementation = L1_9444
SpawnParticleEffect = L0_9443
