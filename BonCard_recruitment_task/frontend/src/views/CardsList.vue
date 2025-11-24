<template>
  <div style="display:flex; justify-content:space-between; align-items:center; margin-bottom:12px;">
    <h3 style="margin:0">Cards</h3>
    <RouterLink class="btn" to="/cards/create">Create card</RouterLink>
  </div>

  <table>
    <thead>
      <tr>
        <th>PIN</th>
        <th>Activation</th>
        <th>Expires</th>
        <th>Balance</th>
        <th></th>
      </tr>
    </thead>
    <tbody>
      <tr v-for="c in cards" :key="c.id">
        <td>{{ c.pin }}</td>
        <td>{{ formatDateTime(c.activation) }}</td>
        <td>{{ formatDate(c.expires_on) }}</td>
        <td>{{ Number(c.balance).toFixed(2) }}</td>
        <td>
          <RouterLink class="link" :to="`/cards/${c.id}/edit`">Edit</RouterLink>
          &nbsp;|&nbsp;
          <button class="link" @click="remove(c.id)" aria-label="Delete card">Delete</button>
        </td>
      </tr>
    </tbody>
  </table>

  <nav class="pager">
    <button class="btn secondary" :disabled="page <= 1" @click="go(page - 1)" aria-label="Previous page">Prev</button>
    <span style="padding: 8px 12px;">Page {{ page }} / {{ lastPage }}</span>
    <button class="btn secondary" :disabled="page >= lastPage" @click="go(page + 1)" aria-label="Next page">Next</button>
  </nav>
</template>

<script setup>
  import { ref, onMounted } from 'vue'
  import { listCards, deleteCard } from '../services/api'
  import { RouterLink } from 'vue-router'

  const cards = ref([])
  const page = ref(1)
  const lastPage = ref(1)

  function formatDateTime(dt) {
    if (!dt) return ''
    const d = new Date(dt)
    return d.toLocaleString()
  }

  function formatDate(dt) {
    if (!dt) return ''
    const d = new Date(dt)
    return d.toLocaleDateString()
  }

  async function load(p = 1) {
    const { data } = await listCards(p)
    cards.value = data.data
    page.value = data.meta.current_page
    lastPage.value = data.meta.last_page
  }

  async function go(p) {
    await load(p)
  }

  async function remove(id) {
    if (!confirm('Delete this card?')) return
    await deleteCard(id)
    await load(page.value)
  }

  onMounted(() => load())
</script>
