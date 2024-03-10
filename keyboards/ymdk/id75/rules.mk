# Configure for 128K flash
MCU_LDSCRIPT = STM32F103xB

# Wildcard to allow APM32 MCU
DFU_SUFFIX_ARGS = -p FFFF -v FFFF


VIA_ENABLE = yes			# Enable VIA
KEY_LOCK_ENABLE = yes		# Enable KC_LOCK support (QK_LOCK)
