<template>
  <form @submit.prevent="submit">
    <fieldset>
      <legend class="sr-only">Card Details</legend>

      <div class="form-group">
        <label class="label" for="card_number">Card number (20 digits)</label>
        <input id="card_number" class="input card-number-input" v-model="form.card_number" inputmode="numeric" maxlength="20" required />
        <p v-if="errors.card_number" class="err">{{ errors.card_number }}</p>
      </div>

      <!-- Row: PIN / Activation / Expires / Balance (stretches across container) -->
      <div class="grid-4">
        <div class="form-group">
          <label class="label" for="pin">PIN (4 digits)</label>
          <input id="pin" class="input pin-input" v-model="form.pin" inputmode="numeric" maxlength="4" autocomplete="one-time-code" pattern="[0-9]*" />
          <p v-if="errors.pin" class="err">{{ errors.pin }}</p>
        </div>

        <div class="form-group">
          <label class="label" for="activation">Activation (date & time)</label>
          <input id="activation" class="input" v-model="form.activation" type="datetime-local" required />
          <p v-if="errors.activation" class="err">{{ errors.activation }}</p>
        </div>

        <div class="form-group">
          <label class="label" for="expires_on">Expires on</label>
          <input id="expires_on" class="input" v-model="form.expires_on" type="date" required />
          <p v-if="errors.expires_on" class="err">{{ errors.expires_on }}</p>
        </div>

        <div class="form-group">
          <label class="label" for="balance">Balance</label>
          <input id="balance" class="input" v-model.number="form.balance" type="number" step="0.01" required />
          <p v-if="errors.balance" class="err">{{ errors.balance }}</p>
        </div>
      </div>

      <div class="form-actions">
        <button class="btn" type="submit">Save</button>
      </div>
    </fieldset>
  </form>
</template>

<script setup>
import { reactive, ref, onMounted, computed } from 'vue'
import { useRoute, useRouter } from 'vue-router'
import { getCard, createCard, updateCard } from '../services/api'

const route = useRoute()
const router = useRouter()

  const form = reactive({ card_number: '', pin: '', activation: '', expires_on: '', balance: 0 })
const errors = reactive({})
const isEdit = computed(() => Boolean(route.params.id))

  // keep simple: v-model handles input; user allowed max lengths via maxlength on inputs

  onMounted(async () => {
    if (isEdit.value) {
      const { data } = await getCard(route.params.id)
      form.card_number = data.card_number
      form.pin = data.pin
      // convert activation datetime to input value
      form.activation = data.activation ? new Date(data.activation).toISOString().slice(0,16) : ''
      // ensure expires_on is a yyyy-mm-dd string for the date input
      if (data.expires_on) {
        const d = new Date(data.expires_on)
        form.expires_on = d.toISOString().slice(0,10)
      } else {
        form.expires_on = ''
      }
      form.balance = Number(data.balance)
    }
  })

function normalizePayload() {
  return {
    card_number: String(form.card_number || '').replace(/\D/g, ''),
    pin: String(form.pin || '').replace(/\D/g, ''),
    activation: form.activation,
    expires_on: form.expires_on,
    balance: form.balance,
  }
}

async function submit() {
  Object.keys(errors).forEach(k => delete errors[k])
  try {
    const payload = normalizePayload()
    if (isEdit.value) {
      await updateCard(route.params.id, payload)
    } else {
      await createCard(payload)
    }
    router.push('/cards')
  } catch (e) {
    const data = e?.response?.data
    if (data && data.errors) {
      for (const k in data.errors) errors[k] = data.errors[k][0]
    }
  }
}
</script>
