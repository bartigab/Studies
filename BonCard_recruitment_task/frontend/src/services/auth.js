import { ref } from 'vue'

// simple reactive auth store used by components
export const user = ref(null)

export function setUser(u) {
  user.value = u
}
export function clearUser() {
  user.value = null
}

// helper to return display name
export function displayName() {
  return user.value?.name || ''
}

export default { user, setUser, clearUser }
