import { createRouter, createWebHistory } from 'vue-router'
import LoginView from '../views/LoginView.vue'
import RegisterView from '../views/RegisterView.vue'
import CardsList from '../views/CardsList.vue'
import CardForm from '../views/CardForm.vue'
import { getUser, getToken } from '../services/api.js'
import { user, setUser } from '../services/auth'


const routes = [
{ path: '/', redirect: '/cards' },
{ path: '/login', component: LoginView },
{ path: '/register', component: RegisterView },
{ path: '/cards', component: CardsList, meta: { auth: true } },
{ path: '/cards/create', component: CardForm, meta: { auth: true } },
{ path: '/cards/:id/edit', component: CardForm, meta: { auth: true } },

]

const router = createRouter({ history: createWebHistory(), routes })


router.beforeEach(async (to) => {
if (!to.meta.auth) return true
try {
if (!getToken()) throw new Error('no-token')
	// if token exists but user not yet populated, fetch profile
	if (!user.value) {
		const { data } = await getUser()
		setUser(data)
	}
return true
} catch {
return { path: '/login', query: { redirect: to.fullPath } }
}
})
export default router