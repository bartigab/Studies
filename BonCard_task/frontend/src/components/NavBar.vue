<template>
    <header class="navbar">
    <div class="brand">BonCard</div>
        <nav>
            <RouterLink to="/cards">Cards</RouterLink>
            <template v-if="user">
              <span style="margin-left:12px; color:var(--text)">Welcome, <strong>{{ user.name }}</strong></span>
              <button class="btn secondary" style="margin-left:12px" @click="onLogout">Logout</button>
            </template>
            <template v-else>
                <RouterLink to="/login">Login</RouterLink>
                <RouterLink to="/register">Register</RouterLink>
            </template>
        </nav>
    </header>
</template>


<script setup>
import { ref,onMounted} from 'vue'
import { logout } from '../services/api'
import { user, clearUser } from '../services/auth'
import { useRouter,RouterLink} from 'vue-router'


const router = useRouter()


onMounted(() => {
    // nothing: user will be set by login/register actions or filled by router guard
})

async function onLogout() {
    try{ await logout(); clearUser(); router.push('/login')}catch { clearUser(); router.push('/login') }
}
</script>