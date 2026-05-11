<template>
<div>

<h2>Register</h2>
    <form @submit.prevent="submit">
    <label class="label">Name</label>
    <input class="input" v-model="form.name" required />


    <label class="label">Email</label>
    <input class="input" v-model="form.email" type="email" required />


    <label class="label">Password</label>
    <input class="input" v-model="form.password" type="password" required />


    <label class="label">Confirm Password</label>
    <input class="input" v-model="form.password_confirmation" type="password" required />


    <div class="form-actions">
        <button class="btn" type="submit">Create account</button>
    </div>

    <p v-if="error" class="err">{{ error }}</p>
    </form>
</div>
</template>


<script setup>
import { reactive, ref } from 'vue'
import { register } from '../services/api'
import { setUser } from '../services/auth'
import { useRouter } from 'vue-router'


const router = useRouter()
const form = reactive({ name: '', email: '', password: '', password_confirmation: '' })
const error = ref('')


async function submit() {
    error.value = ''
    try {
    const data = await register(form)
    // response includes token and user
    if (data?.user) setUser(data.user)
    router.push('/cards')
    } catch (e) {
        // Show detailed server error when available to help debugging
        if (e.response && e.response.data) {
            // validation errors come as e.response.data.errors
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
            error.value = 'Registration failed'
        }
    }
}
</script>