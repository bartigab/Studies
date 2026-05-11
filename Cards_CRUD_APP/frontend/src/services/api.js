import axios from 'axios'


export const api = axios.create({
	baseURL: 'http://localhost:8000',
	headers: { 'X-Requested-With': 'XMLHttpRequest' },
})

const TOKEN_KEY = 'boncard_token'

export function setToken(token) {
	localStorage.setItem(TOKEN_KEY, token)
}
export function getToken() {
	return localStorage.getItem(TOKEN_KEY)
}
export function clearToken() {
	localStorage.removeItem(TOKEN_KEY)
}


api.interceptors.request.use((config) => {
	const t = getToken()
	if (t) config.headers.Authorization = `Bearer ${t}`
	return config
})

api.interceptors.response.use(
	(res) => res,
	(err) => Promise.reject(err)
)


export const login = async (payload) => {
	const { data } = await api.post('/api/login', payload)
	setToken(data.token)
	return data
}
export const register = async (payload) => {
	const { data } = await api.post('/api/register', payload)
	setToken(data.token)
	return data
}
export const logout = async () => {
	try { await api.post('/api/logout') } catch {}
	clearToken()
}
export const getUser = () => api.get('/api/me')

export const listCards = (page = 1) => api.get(`/api/cards?page=${page}`)
export const getCard = (id) => api.get(`/api/cards/${id}`)
export const createCard = (data) => api.post('/api/cards', data)
export const updateCard = (id, data) => api.put(`/api/cards/${id}`, data)
export const deleteCard = (id) => api.delete(`/api/cards/${id}`)