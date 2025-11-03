<template>
<div>
<h2>Login</h2>
    <form @submit.prevent="submit">
        <label class="label">Email</label>
        <input class="input" v-model="form.email" type="email" required />


        <label class="label">Password</label>
        <input class="input" v-model="form.password" type="password" required />


            <div class="form-actions">
                <button class="btn" type="submit">Sign in</button>
            </div>

        <p v-if="error" class="err">{{ error }}</p>
    </form>
</div>
</template>


<script setup>
import { reactive, ref } from 'vue'
import { login } from '../services/api'
import { setUser } from '../services/auth'
import { useRoute, useRouter } from 'vue-router'


const router = useRouter()
const route = useRoute()
const form = reactive({ email: '', password: '' })
const error = ref('')

async function submit() {
error.value = ''
try {
    const data = await login(form)
    if (data?.user) setUser(data.user)
    router.push(route.query.redirect?.toString() || '/cards')
    } catch (e) {
        // show server-provided error when available
        if (e.response && e.response.data) {
            if (e.response.data.errors) {
                const first = Object.values(e.response.data.errors)[0]
                error.value = Array.isArray(first) ? first[0] : String(first)
            } else if (e.response.data.message) {
                error.value = e.response.data.message
            } else {
                error.value = JSON.stringify(e.response.data)
            }
        } else if (e.message) {
            error.value = e.message
        } else {
            error.value = 'Invalid!'
        }
    }
}
</script>